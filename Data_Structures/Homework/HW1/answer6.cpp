#include <iostream>
#include <string>

using namespace std;


int main(){
    try{
        int p;    
        cout << "Input your value of p"<< endl;  //frontuser input numerator
        cin >> p;
    
        int q;
        cout << "Input your value of q"<< endl; //frontuser input  denominator
        cin >> q;



        if(q == 0){          //if q is 0 than throw a que
            throw 99;      
        }
        float r;           //division product
        r = 1.0*p/q;       // int division trick it into make it a decimal
        cout << r << endl;

    
    }catch(int x){           //will catch the que given by the if statement
            cout << "you cannot divide by zero" << endl;
        }
    
}
