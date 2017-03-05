// Comp11
// HW 4
// Programing 1
// Sheng Xu

#include <iostream>
using namespace std;
//initialize function swap;
void swap(int& num1, int& num2);

int main()
{
  int num1, num2,num3,num4;
  //input numbers
  cout << "Please input four numbers" << endl;
  cin>> num1;
  cin>> num2;
  cin>> num3;
  cin>> num4;
  //using swap to order numbers.
  swap(num1, num2);
  swap(num1, num3);
  swap(num1, num4);
  swap(num2, num3);
  swap(num2, num4);
  swap(num3, num4);
  //Return Sorted number
  cout<< "Here are the ordered numbers:" 
      << endl;
  cout<< num1 << " " << num2 << " " << num3
      << " " << num4 <<endl;
}

void swap(int& num1, int& num2)
{
  int temp;
  //Swap the first argument with the second if 
  //the first argument is larger than the second.
  if (num1 > num2)
    {
      temp = num1;
      num1 = num2;
      num2 = temp;
    }
  return;
}
