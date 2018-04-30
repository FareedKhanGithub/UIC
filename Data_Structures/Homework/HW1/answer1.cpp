//This is the finished Homework 1 Problem 1

#include <iostream>    //Input and output string
#include <sstream>     //is string 


using namespace std;
int main()
{
    int x,y;         //x and y are integers
    cout << "give a positive integer x: ";
    cin >> x;   //inputs change this is allows frontuserinput
    cout << "give a positive integer y: ";
    cin >> y;     //this allows for frontuser to type numbers in


    cout << "The GCD of "<< x << " and " << y << "is" << endl;

    ostringstream s;      //output string gives out string little by little
                        
    s << "gcd(" << x << "," << y << ") = ";    //this is just a string   

    
    int r;                      //this int is part of remainder
    while (r != 0)  //while r does not equal zero do this computation 
        {
        r = x % y;  // remainder calculation
        cout << "  x = " << x << "  y = " << y << "  r = " << r << endl;
        x = y;        //saving Y into X giving Y the value to the remainder.
        y = r;
        }
    cout << s.str() << x << endl;        
    return 0;             
}

