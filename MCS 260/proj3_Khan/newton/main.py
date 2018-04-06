#!/usr/bin/env python
#file: main.py
#260su16, lowman, W8L1
""" program to import poly.py to use functions get poly and eval poly_prine(),
newton() to find roots of polynomial.

Do:
1. input polynomial
2. prompt for: x0, tol, MAX_ITR
3. call newton tofind roots (if exists)
4. user can repeat with same polynomial but different  x0, tol and 
MAX_ITR.

5. newton() tests for divide-by-zero, method not converging.
"""

import poly

def get_poly():
    """allocates memory in a list allows frontuser to input things in a list"""
    print "P(x) = a0 + a1*x + a2*x^2 + ... + an * x*"
    print "where n = degree of P(x)"
    adeg = input("enter degree:")
    a = [0.0 for i in range(adeg+1)]                          #set memory aside for the list allocating mem.
    print "adeg:", adeg                                    # just a simple print
    print "a: ",a     

    for i in range(adeg+1):             
        a[i] = input("a[%d]: "%(i))                       #i is simply fro display in the input. 
    p = "%.2f" %(a[0])                              #instills a variable with the intial element in list a
    for i in range(1,adeg+1):             #adeg has an extra one so it takes into account for the intial term 
        p = p + " + %.2f*x^%d"%(a[i],i)      
    print "P(x) = " + p
    return a,adeg


def main():
    """citing all functions, and gathers data from user"""

    a,adeg = get_poly()            #THis is the function that uses the function in this program
    while True:             #while each situation can work while the code goes off
        x0 = input("x0: ")      #first guess for the root polynomial
        tol = input("tol: ")    #error boundary has to be less than this number. 
        max_itr = input("max_itr: ")        #close close for each try
        poly.newton(a,adeg,x0,tol,max_itr)               #poly. is the ciation from import poly          #newton is the funciton we are calling to be done in calculation.    
        print "enter 1 to repeat with new x0,tol,max_itr"    #print statment
        
        
        ans = input ("again 1: or quit 0:")  # this is just a break sequence because this is a while loop            
        if ans == 1:
            continue
        else:
            break

if __name__ == "__main__":
    main()

