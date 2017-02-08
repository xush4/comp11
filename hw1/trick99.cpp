//Comp11
//HW1
//Problem 3
//Sheng Xu
#include <iostream>
int main()
{
  using namespace std;
  int num1=10, num2=99, sum, a, result;
  //players input
  cout<< "Player1, please input a number(10-49)"<<endl;
  cin>>num1;
  cout<< "Player2, please input a number(50-99)"<<endl;
  cin>>num2;
  //factor
  num1=99-num1;
  sum=num1+num2;
  //add hundreds digit to units
  a=sum%100+sum/100;
  //Substract player2 bya
  result=num2-a;
  //output
  cout<< "Actual Result " <<result<<endl;
  cout<< endl;
  cout<< "Player1 is right"<<endl;
}