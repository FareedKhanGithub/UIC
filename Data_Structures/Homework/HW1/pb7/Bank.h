#include <iostream>      //library of input and output stream
#include <string>         //library of string functions is not default 
#include <sstream>       // allows osstringstream
#include <iomanip>     //used for setfill


#ifndef BANK_H
#define BANK_H

using namespace std;

class Bank{
    public:                                 //makes all these global variables    
        float withdraw(float x);      //calls withdraw function
    
        float deposit(float y);      //calls deposit function

        Bank(float intialbal2);      // calls Bank constructor 

        string to_string() const;    //call to_string function
    private:
        float bal;  //makes Balence private so the user cannot see or tamper with it
    protected:


    };
#endif
