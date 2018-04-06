import math

def getabc(line):
    """these numbers are converting the numbers in data.txt file
    and converting them into float numbers which can be passed into other functions"""
    line = line.split()
    a = float(line[0])  
    b = float(line[1])                          
    c = float(line[2])      
    return a,b,c

def disc(a,b,c):                
    """The discriminant tells you about the "nature" of the roots of a quadratic equation."""                                     
    d =((b**2) - (4*a*c))       
    return d

def equal(a,b,c,d):
    """ when f(a) and f(b) and f(c) have a dicriminant that equals to zero"""
    j = float(((-b)+ (math.sqrt(abs((b**2)-(4*a*c)))))/(2*a))    
    s = "When the discriminant is equal to zero the double root is %.2f " % j
    return s     

   
def more(a,b,c,d):
    """when f(a) and f(b) and f(c) have a discriminant thatmore than zero"""
    z = float((-(b)+ (math.sqrt(abs((b**2)-(4*a*c)))))/(2*a))
    g = float((-(b)- (math.sqrt(abs((b**2)-(4*a*c)))))/(2*a))
    s = "When the discriminant is more than zero the roots are %.2f and %.2f" % (z,g)
    return s

def less(a,b,c,d):
    """when f(a) and f(b) and f(c) have a discriminant that less than zero"""
    u = float(-b / (2*a))  
    w = float(math.sqrt(abs(b**2 - 4*a*c)))/ (2*a)
    s =  "When the discriminant is less than zero the roots are (%.2f + %.2fi) and (%.2f - %.2fi)" %(u,w,u,w)
    return s

def zero(a,b,c):
    """The number it will be multiplied by zero, therefore will result in zero """
    s = "The root is all complex numbers"
    return s


def not_zero(a,b,c):
    """ because denominator is zero and numerator is not zero, it is impossible to calculate"""
    s = "no real or complex roots"
    return s


def not_b(a,b,c):
    """Working with the equation ax^2 + bx + c = 0 we ignore the ax^2 because a = 0, and then if rearrange x = (-c/b) """
    x = float(-c/b)    
    s = "The root is %.2f" % x
    return s


def quad(a,b,c,d): 
    """a == 0 leads to a zero in denominator of the quadratic formula, therefore quadratic formula cant be used."""
    if a == 0:             
        if b == 0:
            if c == 0:
                s = zero(a,b,c)
            if not c == 0:
                """Because having any number that is not zero in the
                numerator when the denominator is zero is not possible"""
                s = not_zero(a,b,c)                    
        if not b == 0:  
            s = not_b(a,b,c)


    if not a == 0:
        if d == 0:
            s = equal(a,b,c,d)             
        if d > 0: 
            s = more(a,b,c,d)
        if d < 0:
            s = less(a,b,c,d)
    return s


def heading(outfile):
    outfile.write("Fareed Khan \n")
    outfile.write("MCS 260 ID 104 \n")


    

def write_summary(outfile,a,b,c,d,s):     
    """ This function is going to be writing to the outfile """
    s1 = "==========================================="
    s2 = "f(x) = ax^2 + bx + c = 0"
    s3 =  "----------------------------------------"
    s4 =  "(a,b,c) = ("+str(a)+", "+str(b)+", "+str(c)+")"
    s5 =  "d = b^2 -4ac = " +str(d)    
    s6 = str(s)

    outfile.write(s1 + "\n")
    outfile.write(s2 + "\n")
    outfile.write(s3 + "\n")
    outfile.write(s4 + "\n")
    outfile.write(s5 + "\n")
    outfile.write(s6 + "\n")



def main():
    """Everything is going to be called here."""
    infile = open ("quadabc.txt","r") # read only 
    outfile = open("quadroots.txt","w")   #write only
    heading(outfile)
    for line in infile:
        line = line.strip()
        if line == "": 
            continue
        if line[0] == '#':
            continue
        print line 
        a,b,c = getabc(line)  #it gets the function and makes it equal to the tuple
        d = disc(a,b,c)
        s = quad(a,b,c,d)
        write_summary(outfile,a,b,c,d,s)
    
    infile.close()
    outfile.close()
if __name__ == "__main__":
    main()


