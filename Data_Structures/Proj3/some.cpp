#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<vector>
#include<fstream>

//BY: Fareed Khan

//Proj 3, Merge sort algortihm

using namespace std;
void mergesort(vector<int>u,vector<int>v,int m)  
            //mergesort function takes in vector u and v , int m 
{
  int size1=u.size(); //size of u
  int size2=v.size(); // size of v
  int fullgroups1=size1/m; //tells us number of full groups from u
  int fullgroups2=size2/m; ////tells us number of full groups from v
  vector<int>b1;      //output vectors
  vector<int>b2;     //output vectors
  vector<int>z;    //temporary holding 
  for(int j=1;j<fullgroups1+1;j++)   
      //determines full chunk of m in the file and itirates 
    {
      for (int n=0; n<m;n++)  //iterates size of m 
	{
	  z.push_back(u[n]);          //pushes m elements of u
	  z.push_back(v[n]);     //pushes m elements of u

	}
      sort(z.begin(),z.end());     //sorts it locally
      for(int k=0; k<2*m;k++)   //iterates thru z 
	{
	  if (j%2)// if j is odd put chuck in b1
	    {
	      b1.push_back(z[k]);
	    }
	  else // if j is even put chuck in b2
	    {
	      b2.push_back(z[k]);
	    }
	}
      for (int l=0;l<m;l++) // get rid of numbers used from the copy of u,v and copy z
	{
	  u.erase(u.begin());
	  v.erase(v.begin());
	  z.erase(z.begin());
	  z.erase(z.begin());
	}
    }
  int size5=b1.size();
  int size6=b2.size();
  if(!u.empty()&&!v.empty())    //if there are still elements in the vectors 
    {            
      if (size5>size6)       //if size5(b1) is the smaller vector
                                //push into the smaller vector  
	{
	  for (int j=0;j<u.size();j++)     //push into copy vector z to sort it
	    {
	      z.push_back(u[j]);
	    }
	  for (int j=0;j<v.size();j++)     //push into copy vector z to sort it 
	    {
	      z.push_back(v[j]);
	    }
	  sort(z.begin(),z.end());    //sort it locally
	  for (int k=0;k<z.size();k++)
	    {
	      b2.push_back(z[k]);       //pushes it into b2
	    }
	}
      else  //in every other case push into B2
	{
	  for(int j=0;j<u.size();j++)   //push into copy vector z to sort it
	    {
	      z.push_back(u[j]);
	    }
	  for(int j=0;j<v.size();j++)    //push into copy vector z to sort it 
	    {
	      z.push_back(v[j]);
	    }
	  sort(z.begin(),z.end());     //sort it locally
	  for (int k=0;k<z.size();k++)
	    {
	      b1.push_back(z[k]);
	    }
	}
      u.clear();    //clear the vectors after there used
      v.clear();
    }
  if(!u.empty())    //exception, if u is not empty than push into z 
    {
      if (size5>size6)     //if b1 is more than b2
	{
	  for (int j=0;j<u.size();j++)   //push u into copy vector z to sort it
	    {
	      z.push_back(u[j]);
	    }
	  sort(z.begin(),z.end());
	  for (int k=0;k<z.size();k++)    //push u into copy vector z to sort it
	    {
	      b2.push_back(z[k]);
	    }
	}
      else
	{
	  for (int j=0;j<u.size();j++)  
	    {
	      z.push_back(u[j]);
	    }
	  sort(z.begin(),z.end());       //sort it locally
	  for (int k=0;k<z.size();k++)
	    {
	      b1.push_back(z[k]);
	    }
	}
      u.clear();
    }
  if(!v.empty())     //exception, if v is not empty than push into z 
    {
      if (size5>size6)     //if b1 is more than b2
	{
	  for (int j=0;j<v.size();j++)    //push u into copy vector z to sort it
	    {
	      z.push_back(v[j]);
	    }
	  sort(z.begin(),z.end());
	  for (int k=0;k<z.size();k++)     //push u into copy vector z to sort it
	    {
	      b2.push_back(z[k]);
	    }
	}
      else
	{
	  for (int j=0;j<v.size();j++)
	    {
	      z.push_back(v[j]);
	    }
	  sort(z.begin(),z.end());     //sort it locally
	  for (int k=0;k<z.size();k++)
	    {
	      b1.push_back(z[k]);
	    }
	}
      u.clear();    //clear the vectors after there used
      v.clear();
    }
  ofstream outfile;
  outfile.open("input1.txt");     //writes to another files
  ofstream outfile2;
  outfile2.open("input2.txt");
  for(int l=0;l<b1.size();l++)  //pushes vector b1 input 1 
    {
      outfile<<b1[l]<<endl;
    }
  for(int l=0;l<b2.size();l++)    //pushes vector b2 input 2 
    {
      outfile2<<b2[l]<<endl;
    }
  int Lchunks=(b2.size()/m);     //chunks in B2   
  for(int j=0; j<Lchunks; j++)      //push B1 into B2
    {
      for(int k=0;k<m;k++)
	{
	  b2.push_back(b1[k]);
	}
      for (int n=0;n<m;n++)      //erase what was pushed into b2 from b1
	{
	  b1.erase(b1.begin());      
	}
    }
  sort(b2.begin(),b2.end());        //sort b2 
  if(!b1.empty())         //if b1 is not empty
    {
      sort(b2.begin(),b2.end());
    }
  remove("output1.txt");      //deletes files, allows clean rewriting 
  remove("output2.txt");     
  ofstream outfile3;        
  outfile3.open("output1.txt");
  ofstream outfile4;
  outfile4.open("output2.txt");
  for(int p=0;p<b1.size();p++)     //b1 into output 1
    {
      outfile4<<b1[p]<<endl;
    }
  for(int p=0;p<b2.size();p++)   //puts b2 into output 2
    {
      outfile3<<b2[p]<<endl;
    }
  vector<int>b3=b2;          //makes a copy of b2 called b3 
  for(int p=0;p<b1.size();p++)
    {
      b3.push_back(b1[p]);      //pushes elements of b2 into b3 at the end 
    }
  sort(b3.begin(),b3.end());     //sorts b3 into sorted.txt
  ofstream outfile5;
  outfile5.open("sorted.txt");
  for(int p=0;p<b3.size();p++)    //writes b3 into sorted.txt
    {
      outfile5<<b3[p]<<endl;
    }
}
int main()
{
  int m; //size of chunks
  cout<< "Set M constraint "<<endl;
  cin>>m;                            //frontuser input of obtaining m
  std::ifstream input("input1.txt");      //this reads from the file
  std::ifstream input2("input1.txt");    //go thru it twice
  std::ifstream input3("output1.txt");   //creates a file that we can write to. 
  std::ifstream input4("output2.txt");
  ofstream outfile;
  outfile.open("output1.txt");     //open files that we can write to. 

  ofstream outfile2;
  outfile2.open("output2.txt");
  vector<int>w;
  vector<int>u;   //interger storages 
  vector<int>v;
  char c;         //allows the number lines in the file to be counted
  string line;
  int numlines=0;
  while (input.get(c))        //count the number lines in the file
    if (c=='\n')
      ++numlines;
  int chunks=numlines/m;         //determines the number of m size chunks
  //putting Input 1 into 2 outputs 
  for (int k=1;k<chunks+1;k++)       //for every m size of chunk in file,
    {
      for (int j=0; j<m; j++)     //read m lines
	{
	  getline(input2,line);
	  int number=std::stoi(line);
	  w.push_back(number);
	}
      sort(w.begin(),w.end());    //sorts individual chunks locally
      if (k%2)       //if k gives a remainder then it is odd.      	
      {      
	  for(int l=0;l<w.size();l++)
	    {
	      outfile<<w[l]<<endl;    //write to output1
	    }
	}
      else   //if its even
	{
	  for(int l=0;l<w.size();l++)
	    {
	      outfile2<<w[l]<<endl;     //write to output2
	    }
	}
      w.clear();     //clear after use
    }
                                    
  if (chunks*m<numlines)       //if there are lines in the file that do not  
    {                   //go evenly into chunks of m. 
      if (chunks%2)     //if chunks are odd
	{
	  for(int j=0; j<(numlines-chunks*m);j++)     //write into vector
	    {
	      getline(input2,line);
	      int number=std::stoi(line);    //convert number line into interger
	      w.push_back(number);      
	    }
	  sort(w.begin(),w.end());      //sort vector w
	  for(int l=0;l<w.size();l++)
	    {
	      outfile2<<w[l]<<endl;      //writes it to output2
	    }
	  w.clear();       //clear after use 
	}
      else      //if chunks are even
	{
	  for(int j=0; j<(numlines-chunks*m);j++)    //write into vector
	    {
	      getline(input2,line);
	      int number=std::stoi(line);         //convert number line into interger
	      w.push_back(number);
	    }
	  sort(w.begin(),w.end());    //sort vector w
	  for(int l=0;l<w.size();l++)
	    {
	      outfile<<w[l]<<endl;   //writes it to output1
	    }
	  w.clear();   //clear after use
	}
    }
  //putting two outputs into Input1 & 2
  for(std::string line; getline(input3, line);)  //reads output1     
    {
	int number = std::stoi(line);    //converts line into numbers
	u.push_back(number);      //pushes into vector
    }
  for(std::string line; getline(input4, line);)    //reads output2
    {
      int number = std::stoi(line);    //converts line into numbers
      v.push_back(number);       //pushes into vector
    }
  remove("input1.txt");    //deletes input1
  mergesort(u,v,m);     //calls mergesort
  return 0;
}
