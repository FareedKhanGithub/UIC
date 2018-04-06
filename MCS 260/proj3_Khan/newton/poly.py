#!/usr/bin/env python

#file: poly.py
""" create some functions to be used with polynomials"""
def eval_poly(a,adeg,x):
    """evaluates poly at x"""
    s = 0 
    for i in range(adeg,-1,-1):
        s = a[i] + x*s
    return float(s)


def poly_prime(a,adeg):
    """ this gives the functions of """
    if adeg == 0:
        return [0.0], 0
    ddeg = adeg - 1                    #rare to have integers in lists so do floats  
    d = [0.0 for i in range(ddeg + 1)]
    for i in range(0,ddeg+1):
        d[i] = (i + 1)*a[i+1]
    return d,ddeg
   

def newton(a,adeg,x0,tol,MAX_ITR):
    """This function limits determines the amount roots given in each situation"""
    d,ddeg = poly_prime(a,adeg)
    print "d,ddeg: ", d,ddeg   
    for i in range(1,MAX_ITR+1):
        px = float(eval_poly(a,adeg,x0)) 
        dx = float(eval_poly(d,ddeg,x0))
        if dx == 0:
            print "f'(x)=0 => divide by zero: Try another guess (x0)" 
            return         #It will leave the function
        x1 = x0 - px/dx
        #x1 = x0 - float(eval_poly(a,adeg,x0)) /float(eval_poly(d,ddeg,x0))
        if abs(x1-x0) < tol:              #found root
            print "root x = %4.2f" % (x1)
            return
        print "%d, x%d: %f" %(i, i,x1)          
        x0 = x1
    print "root not found in MAX_ITR = %d iterations, try another guess x0" %(MAX_ITR)
    print "or increase MAX_ITR"
    return 
                                            #UPdate guess and return

def main():
    """ test driver """
    """
    a = [2,3,4]
    deg = 2
    x = 2                                       #THis can be used indvidually
                                                #When not linked to main.py
    px = eval_poly(a,deg,x)
    print deg,a,x,px
    d,ddeg = poly_prime(a,deg)
    
    print a,deg
    print d,ddeg
    """
    #-------------------above from w7L1---------------------
    """P(x) = x^2 - 5x + 6"""
    """These are data already instilled in the program for the individual poly.py to run on its own"""
    #a = [6,-5,1]
    a = [3,-2,1]
    deg = 2
    x0 = 1        #was able to be partially used when the code was by itself
    tol = 0.1
    MAX = 10000
    x0,tol,max_itr = get_poly()

    newton(a,deg,x0,tol,MAX) 
    
if __name__ == "__main__":
    main()
