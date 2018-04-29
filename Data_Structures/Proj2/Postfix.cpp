#include <stack>
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;


stack<char> mystack;
char operand1;
char answer;

void changecase(){
    operand1 = mystack.top(); mystack.pop();//just assigns a variable to the top element of stack
    if (islower(operand1)){                     //if the letter is lowerrcase
        answer = toupper(operand1);             //changes it to uppercase
        mystack.push(answer);                   //pushes new letter to stack;
    }
    else if (isupper(operand1)){                     //same thing for uppercase
        answer = tolower(operand1);
        mystack.push(answer);
    }
}

void swap(){
    operand1 = mystack.top(); mystack.pop();
    char operand2 = mystack.top();mystack.pop();
    mystack.push(operand1);
    mystack.push(operand2);
}

void add(){
    operand1 = mystack.top(); mystack.pop();
    if (operand1==90){                              //if it is z
        answer = 97;                                //changes it to a
        mystack.push(answer);
    }
    else if (operand1 == 122){                      //if it is Z
        answer = 65;                                //changes it to A
        mystack.push(answer);
    }
    else{
        answer = operand1 + 1;                      //switches any other letter to next letter
        mystack.push(answer);
    }
}

void multiply(char k){
    operand1 = mystack.top();
    int a = int(k);
    a = a-48;
    if (a == 0){                        //if its 0 times nothing gets printed
        mystack.pop();
    }
    else{
        mystack.pop();
        for(int n = 0; n < a ; n++){       //keeps repeating letter the number of times;
            mystack.push(operand1);
        }
    }
    
}

void Evaluate(char j){
    if(isdigit(j)){                 //numbers
        multiply(j);
    }
    else if(j == 38){                                //& swap
        swap();
    }
    else if(j == 42){                                    //*
        
        changecase();
    }
    else if(j == 43){                                        //+
        add();
    }
    
}
int main(){
    cout << "Input: ";
    string finp = "";     //this is a blank storage   //front user inp
    cin >> finp;      //frontuser input string has been created
    for(int i = 0;i < finp.size();i++){       //now reading each char as it occur;
        char j = finp[i];     //this breaks up string into little chars
        //the first if statement removes the forieggn chars $ example
        if(isdigit(j)||           // 0 to 9    //operator need if
           isalpha(j)||            //letters
           j == 38 ||                        //&
           j == 42 ||                        //*
           j == 43 )                         //+      //inside evaluation
        {
            if(isalpha(j)){                 //check to see if it is a letter
                mystack.push(j);
            }
            if(isdigit(j) || j == 38 ||                     //evaluate operators
               j == 42 || j == 43){
                Evaluate(j);
            }
            
        }
        
        else{                                                   //outside club //the ignored ones
            cout << "character " << finp[i] << " ignored." << endl;
            //Move on to next loop iteration and next character
        }
        
    }
    int size = mystack.size();
    cout<< "Expression evaluates to ";
    for (int i =1; i <= size ;i++){
        cout<<mystack.top();
        mystack.pop();
    }
    cout<<endl;
    return 0;
}



