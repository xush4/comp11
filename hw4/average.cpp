// Comp11
// HW 4
// Programing 2
// Sheng Xu

# include <iostream>
// Define the length of vector 
const int len=5;
double average(int *numbers);

int main()
{
  using namespace std;
  //Input 5 number.
  cout<< "Please input 5 integers" << endl;
  //len =5; 
  int numbers[len];
  for (int i=0; i<5 ;i++)
    cin>> numbers[i];
  //Call Average
  double ave = average(numbers);
  //Output
  cout<< "The average is "<< ave << "."
      << endl;
}

double average(int numbers[len])
{
  double sum=0, ave;
  // get sum
  for (int i=0; i<len; i++)
    sum += numbers[i];
  // get average
  ave = sum/len;
  // Return Value
  return ave;
}
