#include <iostream>
//Triple Loop Number 5

using namespace std;

int main(){
    int a[20];
    int b[20];
    int c[20];
    int dup = 0;
for(int i=0;i<20;i++)
    {
        a[i] = i;
    }

for(int i=5;i<25;i++)            //These numbers are just random numbers 
    {                                //systematically there just for repition catching
        b[i-5] = i;
    }

for(int i=12;i<32;i++)
    {
        c[i-12] = i;
    }

//Arrays developed///////////////////////////////////////////////



for(int i =0; i<20; i++){      //these for loops are here for the comparision

    for(int j =0; j<20; j++){

        for(int k =0; k<20; k++){
            if (a[i] == b[j]){     //if a[i]element equal b[j]elemnt for loop activates
                dup += 1;  }
            if (a[i] == c[k]){    //if a[i] element equal c[k] k element for loop active
                dup += 1;}
    //with each for loop activation we get a duplication count.
    cout<<"  " << dup << "   " << a[i]<< "  " << b[j] <<"   " << c[k]<< "   "  << endl;
        
        }
    }
}

}


