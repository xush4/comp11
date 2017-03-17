#include <iostream>
#include <iomanip>
#include <limits>
#include <stdio.h>
using namespace std;

int main() {
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";    
    // Declare second integer, double, and String variables.
   int a;
   double b;
   string s1;
   cin>>a;
   cin>>b;
   string s2;
   cin.ignore(); //Adding cin.ignore() to the next line clears/ignores the 		    //newline from the stream.
   getline(cin,s1);
   s2 = s + s1;
   cout<<a+i<<endl;
   printf("%.1f \n", d+b);
   cout<< s2<<endl;   
}
