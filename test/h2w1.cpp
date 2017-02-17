#include <iostream>

using namespace std;

int main() 
{ 
if (6 < 2 * 5){
cout << "Hello";}
cout << " there";
cout << endl;

if (6 > 2 * 5){
cout << "Hello";}
cout << " there";
cout << endl;

int x=3, y=2,z;
if (x > 2) 
{
    if (y > 2) 
    {
        z = x + y;
        cout << "z is " << z;
    }
}
else
     cout << "x is " << x;
cout << endl;

int a=1,b=2;
if (a < b)
{
cout << "*";
a++;
}
else if (a == b)
cout << "&";
else
cout << "$";
cout << endl;

int day=5;
switch (day)
  {
    case 1 :
    case 7 : cout << "This is a weekend day";
             break;
    case 2 :
    case 3 :
case 4 :
    case 5 :
    case 6 : cout << "This is a weekday";
             break;
    default : cout << "Not a legal day";
              break;
  }

}