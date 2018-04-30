#include <iostream>
#include <stdlib.h>

using namespace std;
int rows;           //rows type of int
int cols;           //cols type of int


int main(){
cout <<"Type in amount of rows:" ;
cin >> rows;                          //frontuser input storage

cout <<"Type in amount of columns:" ;
cin >> cols;                         //frontuser input storage

cout << "Random Integer Matrix of Numbers" << endl; 
int a[rows][cols];     
for(int i=0; i<rows; i++){      //when i base is less than rows continue computation
    for(int j=0; j<cols; j++){  //when j base is less than cols continue with computation
        a[i][j] = rand() % 1000;  //this then creates a mainframe in which random 
        cout << a[i][j]<<" ";
    }                                //random is being chosen from 1 to 1000
    cout <<endl;
}




int Max = 0, MaxRowIndex = 0, MaxColIndex = 0;       //these are the defaults
for(int i=0; i<rows; i++){        //increment of rows
    for(int j=0; j<cols; j++){     //increments of cols
        if(Max < a[i][j]){  // intially starting off with 0 updates with the max number           
Max = a[i][j];                     //max is stores the largest number here
MaxRowIndex = i;    //this then takes apart of the location of the max element
MaxColIndex = j;       
}
}
}





cout<<"Largest element in the matrix is "<<Max<<endl;
cout<<"Max Row index is "<<MaxRowIndex<<endl;               //Prints
cout<<"Max Column Index is "<<MaxColIndex<<endl;

return 0;
}
