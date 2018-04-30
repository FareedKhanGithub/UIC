using namespace std;
#include <iostream>      //library of input and output stream
#include <string>         //library of string functions is not default 
#include <sstream>      //for osstringstream ability
#include <iomanip>     //for set fill ability



class Bank{     
    public:           
        float withdraw(float x){//function withdrawal has variable float x updating result
            bal = (bal-x);  //user withdrawal money which is a negative in the bank
            return bal;                    //new updated version of bal
        }

        float deposit(float y){//funciton deposit has variable float x for updating result
            bal = (bal+y);      // user deposit money which is a positive in bank
            return bal;             
        }
    
        Bank(float intialbal2){         
            bal = intialbal2;                                   
        }
            //intialbal2 once, this runs first and sets tempo 
               //intailbal2 is the amount the user has stored in the bank which is main
           //and then Bal will then update and then changed intialbal2 for program 
        

        

        string to_string() const{        
        using std::ostringstream;
        ostringstream s;        
        s << setfill('0')
        << std::fixed << std::setprecision(2) << "Here is your updated balance " << bal << endl;
        return s.str();     //mashes all the strings together
            }


    private:                    
                            
    protected:  //available in the class that defines them and in the classes that inherit from that class.

        float bal;
};




class Savings_Account:public Bank{
    public:
        float update(){      
            bal = interest * bal;
        return bal;
        }

    
        
        //the constructor
        Savings_Account(float savbal,float inter) : Bank(savbal){//THis is the constructor                                 
            interest = inter;        
            bal = savbal;
        }
        
        //savbal once, this runs first and sets tempo
             //savbal is the amount the user has stored in the bank which is main
           //and then Bal will then update and then changed savbal for program 
        //this savbal is shared with bal in the bank class
    

        
        string to_string() const{        //dont forget to cite the class
        using std::ostringstream;
        ostringstream s;        
        s << std::fixed << std::setprecision(4) <<"Here is the interest rate: " 
        << interest << endl << setfill('0')
        << std::fixed << std::setprecision(2) 
        << "Here is your updated balance: " << bal << endl;
        return s.str();     //mashes it all together
            }

    private:
        float interest;      //variable we dont want the user to tamper with or see
        
    protected:
};






int main(){
    Bank vault(1000);      //user has 1000 in bank
    vault.withdraw(50);       //user withdrew 50 dollars from bank
    vault.deposit(92);          //front user puts this amount of money in bank
    Savings_Account check(1000,.0001);        //these fill in the role of the constructor
    cout << vault.to_string() << endl; 
    check.update();
    cout << check.to_string() << endl;
    }
    
