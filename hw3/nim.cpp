//Comp11
//HW3
//PROGRAM 2
//SHENG XU
#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
  using namespace std;
  string start;
  //remember how many games player wins.
  int num_player_win=0;
  //enter Heads or Tails
  do
    {  
      cout<< "Welcome to nim. I'll flip a coin. Heads or Tails?" << endl;
      cin>> start;
    } while (start != "Heads" && start != "Tails");
  srand(time(0));
  //Change heads to 0, tails to 1.
  int player_input_number=0;
  if (start == "Tails")
    {
      player_input_number = 1;
    }
  //Generate Random 0 or 1
  int start_output_number = rand()%2;
  // if player's guess fits random number. He will start Game1 first.
  bool player_start_Game1 = false;
  if(player_input_number == start_output_number)
    {
      player_start_Game1 = true;
    }
  //set a flag for whom start the game 1.
  bool  player_start_Game = player_start_Game1;
  //Play 3 times.
  for (int i = 1 ; i <= 3 ; i++)
    {
      bool player_win;
      
      // Generate a number in 5-30
      srand(time(0));
      int num_of_beans = 5+rand()%26;
      //set a flag. player start Game 1 if he guess right.
      bool player_play = player_start_Game;
      cout<< "Game " << i << " ";
      if (player_start_Game)
	{
	  cout<< "You Start! There are " << num_of_beans << " beans. ";
	}
      else
	{
	  cout<< "I start! There are " << num_of_beans << " beans. ";
	}
      
      do
	{	 
	  if (player_play)// Player's turn
	    {
	      int num_player_take;
	      do
		{
		  cout<< "How many beans do you want to take?" << endl;
		  cout<< "Please input 1, 2, and 3. Do not exceed the number of beans left." << endl;
		  cin>> num_player_take;
		}while(num_player_take < 1 || num_player_take > 3 || num_player_take > num_of_beans);
	      num_of_beans -= num_player_take;
	      if(num_of_beans == 0)
		{
		  player_win = false;
		}
	      cout<< "You take "<<num_player_take<<" beans."<<endl;
	      cout<< "There are "<<num_of_beans<<" beans left! "<<endl;
	      cout<< endl;
	    } 
	  else //computer's turn
	    {
	      //take a random number in 1-3
	      srand(time(0));
	      int num_I_take = 1+rand()%3; 
	      if (num_I_take >= num_of_beans && num_of_beans!=1)
		{
		  num_I_take = num_of_beans-1;
		} 
	      else if(num_of_beans == 1)
		{
		  num_I_take = 1;
		  player_win = true;
		}
	      num_of_beans -= num_I_take;
	      cout<< "I'll take " << num_I_take << " beans." <<endl;
	      cout<< "There are " << num_of_beans << " beans left! "<<endl;
	    }
	  // Change Turn. i.e. Change flag.
	  player_play = not player_play;
	}while(num_of_beans > 0);
      //Output	Result.
      cout<< endl;
      //cout<< endl;
      if(player_win)
	{
	  cout<< "You win this round!" <<endl;
	  num_player_win++;
	}
      else
	{
	  cout<< "You've lost this round!" <<endl;
	}
      cout<< endl;
      //Change who starts the game.
      player_start_Game= not player_start_Game;
    }  
  if(num_player_win > 1)
    cout<<"You win the 3-round game."<<endl;
  else
    cout<<"Sorry, you've lost the 3-round game."<<endl;
  return 0;
}
