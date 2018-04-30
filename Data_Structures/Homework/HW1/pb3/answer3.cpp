#include<iostream>
#include<fstream>
using namespace std;
int main()
{
fstream getFile;        //makes input stream
char ch;                //ch signifies char
int count_vowels = 0;   //give int to count_vowels starts at zero


getFile.open("testingas.txt");
while(!getFile.eof())     //will run until the file is done reading
{
getFile.get(ch);
  
// Check each character whether it is vowel or not if the character is vowel count it.

if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')    
count_vowels++;      //Counting the number of vowels    // character == 'a' or

}

getFile.close();          //Close input file




if(count_vowels>1000)                      //These are the exceptions
cout <<" The file Contains more than 1000 Vowels :"<<endl;   //Prints
else
cout <<"The file Contains less than 1000 Vowels:"<<endl;
  


cout<<"Amount of Vowels in the file are :"<<count_vowels<<endl;   //This will print regardless
return 0;           //return null

}
