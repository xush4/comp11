/********************
* COMP11
* Homework 2
* Problem 2
* Sheng X
*
* Test input: 3, bike, wheel, frame
* Expected output: bike, frame, wheel
*
* Test input: 6, 4, apple, elephant, dog, cat
* Expected output: apple, cat, dog, elephant
*
* Test input: 3, xanadu, abba, jellyfish
* Expected output: abba, jellyfish, xanadu
*********************/

#include <iostream>
#include <string>
using namespace std;
int main(){ 
  //Initialize Variables
  //Inputs
  int k;
  do {
    cout<<"Please Input A number in 2 to 5!"<<endl;
    cin >> k;
  }while (k>5 || k<2);
  const int n = k;
  //cout<< n;
  string *str=new string[n];
  //Enter strings and store in array
  for(int i=0;i<n;i++){
    cout<<"Please input word "<<i+1<<" :"<<endl;
    cin>>str[i];}
  
  //A standard "bubble sort"
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
  cout<<endl<<"sorted strings:"<<endl;
  for(int i=0;i<n;i++)
    cout<<str[i]<<endl;
  return 0;
}
