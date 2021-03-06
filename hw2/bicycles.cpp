/********************
* COMP11
* Homework 2
* Problem 3
* Laney Strange
*
* Test input: 2 wheels, 1 frame, 50 links
* Expected output: 1 bike built. 0 leftover.
*
* Test input: 3 wheels, 10 frames, -500 links
* Expected output: 1 bike built. Leftover: 1 wheel, 9 frames, 450 links.
*
* Test input: 10 wheels, 7 frames, 250 links
* Expected output: 5 bikes built. Leftover: 0 wheels, 2 frames, 0 links.
*
* Test input: -1 wheels
* Expexted out put: Not enough for a bike.
*********************/

#include <iostream>
#include <string>

int main()
{
  using namespace std;
  //The following 3 numbers are not useful. Just created for test convenience.
  int num_of_wheels = 0, num_of_frames = 0, num_of_links = 0;
  //An temporary Variables.
  int num=0;
  // number of bikes
  int num_of_bikes = 0;
  // num of parts needed for a bike.
  const int num_per_bike[3]={2,1,50};
  // num of parts(input by user)
  int num_of_parts[3]={num_of_wheels,num_of_frames,num_of_links};
  int num_of_remain;
  string category[3] = {"wheels","frames","links"};
  // cout<<category[1]<<endl;//test
  // 3 inputs
  for (int i=0;i<3;i++){
    do {
      cout<< "How many "<<category[i]<<" do you have?"<<endl;
      cin>>num;
      // Re-input if not enough for a bike.
      if (num/num_per_bike[i]==0)
	{
	  cout<<"Not Enough for a bike! Please input again! ";
	}
      // Change negative to positive.
      else if (num<0)
	{
	  num=-num;
	  cout<<"Your input is negative. I will take it as "<< num<<"."<<endl;
	}
    }while(num/num_per_bike[i]==0);
    num_of_parts[i]=num;
    cout<<"That's enough for "<<num/num_per_bike[i]<<" bikes."<<endl;
  }
  cout<<endl;
  //calculate how many bikes we can make.
  for (int i=0;i<3;i++){
    num=num_of_parts[i]/num_per_bike[i];
    if(num_of_bikes==0 || num<num_of_bikes)
      {
	num_of_bikes=num;
      }
  }
  //Output number of bikes.
  cout<<"I can make "<<num_of_bikes<<" bikes, come back tomorrow."<<endl;
  cout<<"There are still:"<<endl; //Output what is left.
  for (int i=0;i<3;i++)
    {
      num_of_remain=num_of_parts[i] - num_of_bikes*num_per_bike[i];
      cout<<num_of_remain<<" "<<category[i]<<" ";
	}
  cout<<"left!"<<endl;
}
