def librar(s):

    L = []
    with open(s,"r") as f:                                     #the cleaner in the text
        book = f.read()
        book = book.lower()
        book = book.replace("?",".")
        book = book.replace("!",".")                                 
        book = book.replace("\n", "")
        Sentances = book.split(".")            #Sentence is a list type
  

    for sentance in Sentances:
        words = sentance.split()                                     #this is where double for loop happens but it isnt nested
        L.append(words)				

    return L



def readinsentimentwords(s):
    L = []

    with open(s,"r") as f:
        for line in f:
            line = line.replace("\n","")                       #more cleaning
            L.append(line)
    return L


def sentimentanalysis(W,P,N):          #all these arguments are lists, so the idea of breaking down into mulitple for loops 
    p = 0
    n = 0
    neut = 0



    for i in range(len(W)):
        words = W[i]
        a = len(set(words) & set(P))
        b = len(set(words) & set(N))
        if a > b:
            p += 1
        elif a < b:
            n += 1
        else:
            neut += 1
    print("word with positive sentiment:",   round(((p)/(p + n + neut)), 3))
    print("words with negative sentiment:", round(((n)/(p + n + neut)), 3))
    print("words with the neutral sentiment:", round(((neut)/(p + n + neut)), 3))


def main():

    W = librar("sherlock.txt")
    P = readinsentimentwords("positive_sentiment.txt")
    N = readinsentimentwords("negative_sentiment.txt")

    sentimentanalysis(W,P,N)

main()