/********************
* COMP11
* Homework 2
* Problem 2
* Sheng XU
*
* Test input: bike, wheel, frame
* Expected output: bike, frame, wheel
*
* Test input: elephant, dog, cat
* Expected output: cat, dog, elephant
*
* Test input: xanadu, abba, jellyfish
* Expected output: abba, jellyfish, xanadu
*********************/

#include <iostream>
#include <string>
using namespace std;
int main(){ 
  //Initialize Variables
  //3 Inputs
  const int n=3;
  string *str=new string[n];
  //Enter strings and store in array
  for(int i=0;i<n;i++){
    cout<<"Please input word "<<i+1<<" :"<<endl;
    cin>>str[i];
  }
  //A standard "bubble sort"(Put bigger value towards the end.)
  for(int i=0;i<n-1;i++)
    {
    for(int j=0;j<n-i-1;j++)
      {
	if(str[j]>str[j+1])
	  {
	    //Exchange 2 elements using temporary variables
	    string temp=str[j];
	    str[j]=str[j+1];
	    str[j+1]=temp;
	  }
      }
    }
  //Output
  cout<<endl<<"sorted strings:"<<endl;
  for(int i=0;i<n;i++)
    cout<<str[i]<<endl;
  return 0;
}
