#include <iostream>
int main()
{
  using namespace std;
  int n=1;
  do
    {
      cout<<n<<" ";
    }while(n++<=3);
  cout<<endl;
  for (int count = 1; count < 5; count++)
    cout << (2 * count) << " ";
  cout<<endl;
  for (int n = 10; n > 0; n = n - 2)
    {
      cout << "Hello ";
      cout << n << endl;
    }
  int i = 1;
  while (i <= 10)
    {
      if (i < 5 && i != 2)
	cout << 'X';
      i++;
    }
  cout<<endl;
  int j;
  for (j = 1; j<=10; j++)
     {
	if (j < 5 && j != 2)
	cout << 'X';
     } 
  cout<<endl;
  n = 5;
  while (--n > 0)
    {
      if (n == 2)
	break;
      cout << n << " ";
    }
cout << "End of Loop.";
  return 0;
}
