
#include <iostream>      //library of input and output stream
#include <string>   //library of string functions is not default 
#include <sstream>   // allows osstringstream
#include <iomanip>     //used for setfill
#include "Bank.h"        //cites the Header file
using namespace std;

    
            
float Bank::withdraw(float x){//function withdrawal has variable float x updating result
            bal = (bal-x);  //user withdrawal money which is a negative in the bank
            cout << endl << to_string() << endl; //runs to_string with updated balence 
            return bal;                    //new updated version of bal
        }


float  Bank::deposit(float y){//funciton deposit has variable float x for updating result
           bal = (bal+y);      // user deposit money which is a positive in bank
           cout << endl << to_string() << endl;
           return bal;              
        }
    


      Bank::Bank(float intialbal2){           
           bal = intialbal2;         //intilbal2 once, this runs first and sets tempo
        }     //intailbal2 is the amount the user has stored in the bank which is main
           //and then Bal will then update and then changed intialbal2 for program 
        
    


     string Bank::to_string()const{     
        using std::ostringstream;
        ostringstream sa;        
        sa << setfill('0')                //creates the string for the recurrent string
 << std::fixed << std::setprecision(2)
 << "Here is your updated balance" << endl << bal;
        return sa.str();     //mashes all these strings together
            }

 
