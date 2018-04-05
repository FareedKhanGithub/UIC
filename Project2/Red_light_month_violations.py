from matplotlib import pyplot as plt
import numpy as np
from collections import OrderedDict




def librar(s):
    D = {}
    with open(s,"r") as f:
        for line in f:
            if not line.startswith("INTERSECTION"):         #to not include the first line because it contains titles
                L = line.split(",")                               #splits by comma
                date = L[3]                   #starting 0  #3 element in row but it contains the year and day
                viol = int(L[4])              #starting 0     #4 element in row
                M = date.split("/")
                mon = int(M[0])                              #month  only

                if mon not in D:                         #makes sure that the sums dont overlapp leaving 12 months
                    D.update({mon:viol})
                else:
                    D[mon] = D[mon] + viol                    #sums over all of the violations for each month
    return D




def plotter(D):
    x = []                                                  #storages
    y = []

    d = OrderedDict(sorted(D.items()))           #it orders the keys without the values falling off

    for k,v in d.items():
        x.append((int(k)))               #months     x axis
        y.append((int(v)))               # viol      y axis

    print(x)
    print(y)

    line = np.polyfit(x, y, 1)
    # 1 specifies that you want a degree 1 polynomial, i.e. a line
    # This returns a numpy array of length 2 containing the coefficients of the best-fit line

    line = list(line)  # Convert it from a numpy array to a list
    a, b = line[0], line[1]

    # Create list of y values from best-fit line
    yfit = [a * xval + b for xval in x]

    # Plot original data as scatterplot
    plt.plot(x, y, "o")

    # Plot best fit line
    plt.plot(x, yfit)

    # Label the axes
    plt.xlabel("x values")
    plt.ylabel("y values")

    plt.show()




def main():
    D = librar("Red_Light_Camera_Violations.csv")
    plotter(D)
main()