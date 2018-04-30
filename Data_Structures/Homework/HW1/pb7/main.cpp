#include <iostream>      //library of input and output stream
#include <string>         //library of string functions is not default 
#include <sstream>      // allows osstringstream
#include <iomanip>     //used for setfill
#include "Bank.h"    //cites the header file

using namespace std;
int main()
     {
    float y;                   
    float z;
    Bank vault(1000);                    //starts off with user money in the bank
    cout << "Here is  your current balance" << vault.to_string() << endl;
    
    cout << "Input withdrawal amount"<< endl;
    cin>>y;  
                        //allows front user input inorder to withdraw to the balence
    vault.withdraw(y); 
    
    cout << "Input deposit amount" << endl;
    cin>>z;            //allows front user input inorder to deposit to the balence
    vault.deposit(z);   
    
    }
 
