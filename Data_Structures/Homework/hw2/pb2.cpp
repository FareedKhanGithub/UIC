#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;




int main(){

vector<int> var;   //variable
vector<int> exp;    //exponential
int q = 0;    
while(q != 3){
        int x;
        int e;    
        cout << "this is the variable" << endl;
        cin >> x;
        cout << "this is the exponent" << endl;
        cin >> e;
        
        var.push_back(x);
        exp.push_back(e);   
        cout << "do you want to leave" << endl;
        cin >> q;   //how you leave
        }
    
if(0 <= var.size())      //the if statement should handle the zero statement   
    {
         for(int i = 0; i < var.size(); i++){    //good
            //cout << var[i] << endl;      
            int sum;
            sum = var[i-1] + 1/var[i];
            cout << sum;
            // recur(x - 1)+ (1/x)    //old return statment

            return sum;
            }
    } 
             
         
    else{
        return 1;     //because factorial of 1 is one  
    }     

    return 0;
}
