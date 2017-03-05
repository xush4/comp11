/* COMP11
 * Spring 2017
 * Lab 3 - Caesar Cipher
 * Daniel Le Breton and Sheng Xu */

#include <iostream> 
#include <string> 
using namespace std; 
string encrypt(string message, int shift)
{
  int len = message.length();
  for(int i=0;i<len;i++)
    {
      //getting ascii # 
      char x = message[i];
      int ascii_x = (int)x;
      //shifting ascii #
      ascii_x+=shift;
      //cout<< ascii_x<<endl;
      while(ascii_x>122)
	{
       //loop from end to beginning
	  ascii_x=ascii_x%122+96;
	}
      //cout<<ascii_x<<endl;
      message[i]= (char) ascii_x;
    }
  return message;
}

string decrypt(string message, int shift)
{
  int len = message.length();
  for(int i=0;i<len;i++)
    {
      char x = message[i];
      int ascii_x = (int)x;
      ascii_x -= shift;
      while(ascii_x<97)
	{
	  ascii_x = ascii_x + 26; 
	}
      message [i] = (char) ascii_x;
    }
  return message;
}
int main()
{
	// Variables for the original message,
	// encrypted message, and shift value 
    string message, encr_message;  
    int shift; 

    cout << "Please enter a message: "; 
	cin >> message;

    cout << "Please enter a shift.\n";
    cin >> shift; 

	// Validate the shift to be > 0
    while (shift < 1)
    {
        cout << "Shift must be > 0.\n";
        cout << "Please enter again. \n"; 
        cin >> shift; 
    }

	// Call the function to encrypt the
	// original message and report
    encr_message = encrypt(message, shift); 

    cout << "\nEncoded message: " 
		 << encr_message << "\n\n"; 
    string decry_message = decrypt(encr_message, shift);

    cout << "Original message: " << decry_message << endl;

    return 0;
}


