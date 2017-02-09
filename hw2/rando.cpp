/********************
* COMP11
* Homework 2
* Problem 1
* Sheng Xu
*********************/

# include <iostream>
# include <ctime>
# include <cstdlib>
using namespace std;
int main(){
  //Using time to generate randon seed
  srand(time(0));
  // Initializee 2 random numbers and ans for answer
  int i=5+rand()%11;
  int ans;
  int j=5+rand()%11;
  cout<<"What is "<<i <<" + "<< j <<"?"<<endl;
  // using do while to do loops
   do {
      cin>>ans;
      if (i+j==ans){
	//True Answer
	cout<<"Correct. Game over!"<<endl;
      }
      else{
	//Wrong answer
	cout<<"Incorrect. Try again. "<<"What is "<<i <<" + "<< j <<"?"<<endl;
      }
   } while (i+j!=ans);
 
  return 0;
}
