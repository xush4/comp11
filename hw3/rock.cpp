//Comp11
//HW3
//PROGRAM 2
//SHENG Xu

//Test1:
// RS PR SR
// 1 win 1 win 2 win 2:1 1 win

//Test2:
//SS RR PP
//tie tie tie 0:0 tie

//Test3:
//SR PP SP
//2 win tie 1 win 1:1 tie

//Test4:
//RP PS RR
//2 win 1 win tie 1:1 tie

//Test5:
//SR SS RP
//2win tie 2win 2:0 2win

#include <iostream>
#include <string>
int main()
{
  using namespace std;
  cout<< "Rock, Scissors, Paper Game."<<endl;
  cout<< "Three rounds of Games. Let's Start!"<<endl;
  cout<< "R for Rock; S for Scissors; P for Paper."<<endl;
  int num_p1_win=0, num_p2_win=0;
  int variable;
  int result[2];
  string input;
  string player_input[3]={"Rock", "Scissors", "Paper"};
  for (int num_of_game = 1; num_of_game <= 3; num_of_game++)
    {
      cout<< "Game " << num_of_game<<endl;
      
      for (int num_of_player = 0; num_of_player <= 1; num_of_player++) 
	{
	  do
	    {
	      cout<<"Player "<< num_of_player+1 <<": R, S, or P?"<<endl;
	      cin>>input;
	      //Store result Numerically.
	      if (input == "R")
		result[num_of_player]=0;
	      else if(input == "S")
		result[num_of_player]=1;
	      else if(input == "P")
		result[num_of_player]=2;	
	    }while(input!="R" && input!="S" && input!="P");
	}
      //Calculate Result
      //bool p1_win=false, p2_win=false, tie=false;
      variable=result[1]-result[0];
      //cout<< variable<<endl;
      if (variable < 0)
	{
	  variable+=3;
	}
      //cout<< variable<<endl;
      if (variable==0)
	{
	  // tie=true;
	  cout<<"It's a tie!"<<endl;
	}
      else if (variable == 1)
	{
	  //p1_win=true;
	  cout<<player_input[result[0]]<<" beats "<< player_input[result[1]];
	  cout<<". Player1 wins Round "<< num_of_game <<"!"<<endl;
	  num_p1_win++;
	}
      else if (variable ==2)
	{
	  //p2_win=true;
	  cout<<player_input[result[1]]<<" beats "<< player_input[result[2]];
	  cout<<". Player2 wins Round "<< num_of_game <<"!"<<endl;
	  num_p2_win++;
	}
      cout<<endl;
    } 
  cout<<"Player1 wins "<<num_p1_win<<" games."<<" ";
  cout<<"Player2 wins "<<num_p2_win<<" games."<<endl;
  if (num_p1_win>num_p2_win)
    cout<<"Player1 wins the 3-round game."<<endl;
  else if(num_p2_win>num_p1_win)
    cout<<"Player2 wins the 3-round game."<<endl;
  else 
    cout<<"Player1 and Player2 tied in the 3-round game."<<endl;
}
