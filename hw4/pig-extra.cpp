//* COMP11
// * Spring 2017
// * HW4 
// * Programing 3 Extra
// * Sheng Xu

// Two dice game
//Two standard dice are rolled. If neither shows a 1, their sum is added to 
//the turn total.
//If a single 1 is rolled, the player scores nothing and the turn ends.
//If two 1s are rolled, the player’s entire score is lost, and the turn ends.
//If a double(not 1s) is rolled,a bonus 10 point is offered to the total number.

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

// Function prototype: check_for_win
int check_for_win(int, int);
// Function prototype: end_round
int end_round(int, int &, int &, int);

// Function to roll die
int roll_dice();

// Function to tell player to stop rolling and also we quit the round automatically to win. 
bool suggestion(int, int, int, int);

// Number of points needed to win
const int THRESHOLD = 45;

int main () 
{
  cout << "Reach " << THRESHOLD << " to win."<< endl;
  // Total number of points for each player.
  int pone_points = 0, ptwo_points = 0;
  
  // Whose turn it is. Player One always starts.
  int turn = 1;
  
  // Is the game over yet
  bool game_over = false;
  int winner;
  // While loop for the game. A game comprises several rounds.
  while( !game_over )
    {
      // Announce whose turn it is
      cout << endl;
      cout << "Player " << turn << " is up!\n";

      // Round-specific variables
      bool round_over = false;
      int round_points = 0;
      while (!round_over)
	{
	  //I prefer to set seed in each round to make it more "Random".
	  srand(time(0));
	  int player_enter;
	  do
	    {
	      cout<< "Enter 0 to roll or 1 to hold"<< endl;
	      cin>> player_enter;
	    }while(player_enter !=0 && player_enter !=1);
	  if (player_enter == 1)
	    {
	      // Round over
	      round_over=true;
	      // Change player's point and change ture.
	      turn = end_round(turn, pone_points, ptwo_points, 
			       round_points);
	      winner = check_for_win(pone_points, ptwo_points);
	      if (winner == 1 || winner==2)
		game_over=true;
	      // Output Current Scores. 
	      cout<< "Curren Score is "<< pone_points << ":" 
		  << ptwo_points<< "." <<endl;
	    }
	  else if (player_enter ==0)
	    {
	      int dice_number=roll_dice();
	      // cout<< "You rolled "<< dice_number<<"."<<endl;
	      if (dice_number ==1)
		{
		  // No points
		  round_points=0;
		  cout<< "You earn no point at this round!"<< endl;
		  cout<< "Curren Score is "<< pone_points << ":" 
		      << ptwo_points<< "." <<endl;
		  // Round Over
		  round_over=true;
		  // Change player's point and change turn.
		  turn = end_round(turn, pone_points, ptwo_points, 
				   round_points);
		}
	      else if  (dice_number ==0)
		{
		  if (turn == 1)
		      pone_points=0;
		  else
		    ptwo_points=0;
		  round_points=0;
		  cout<< "You lose all your points at this round!"<< endl;
		  cout<< "Curren Score is "<< pone_points << ":" 
		      << ptwo_points<< "." <<endl;
		  // Round Over
		  round_over=true;
		  // Change player's point and change turn.
		  turn = end_round(turn, pone_points, ptwo_points, 
				   round_points); 
		}
	      else 
		{
		  //Add points to current round
		  round_points+=dice_number;
		  cout<< "You have "<< round_points<<" in this round."
		      <<endl;
		  if (suggestion(turn, pone_points, ptwo_points, round_points))
		    {
		      round_over=true;
		      game_over=true;
		      turn = end_round(turn, pone_points, ptwo_points, 
			       round_points);
		      winner = check_for_win(pone_points, ptwo_points);
		    }
		}
	    }
	}		
    } // end game while loop
  //Output Result
  cout << "Player" <<" " << winner << " " << "wins." << endl;
  // Game is over. End the program.
  cout << "Thanks for playing!\n";
	return 0;
}

int roll_dice()
{
  int number1 = 1 + rand()%6;
  int number2 = 1 + rand()%6;
  int number;
  if (number1==1 && number2==1)
    number = 0;
  else if (number1==1 || number2==1)
    number = 1;
  else if (number1 == number2)
    number = number1 + number2 + 10;
  else    
    number = number1 + number2;
  cout<< endl;
  cout<< "You rolled " << number1 << " and "<< number2<<endl; 
  return number;
}


/****************************************
 * NO NEED TO MODIFY CODE BELOW THIS POINT    *
 ****************************************/

// FUNCTION DEFINITION
// Function check_for_win
// Arguments:
//	Player 1 and 2's points (ints)
// Returns:
//	0 is game is not over
// 	1 if player one won
// 	2 if player two won
// Does:
// 	Compares each score to the threshold
int check_for_win(int pone_points, int ptwo_points)
{
	// Check the players' current points against the threshold
	if( pone_points >= THRESHOLD ) 
	{			
		return 1;
	}
	else if( ptwo_points >= THRESHOLD )
	{
		return 2;
	}	
	
	// If we didn't meet either condition,
	// then nobody won
	return 0;
}

// FUNCTION DEFINITION
// Function end_round
// Arguments:
// 	1. whose turn it is (int)
//	2. player one's points (int, by ref)
// 	3. player two's points (int by ref)
// 	4. round points (int)
// Returns:
//	# of updated turn
// Does:
//	Updates p1 and p2 points
//	Switches whose turn it is
int end_round(int turn, int &pone_points, int &ptwo_points, int round_points)
{
	if(turn == 1)
	{
		pone_points += round_points;
		return 2;
	}
	else{
		ptwo_points += round_points;
		return 1;
	}

}

bool suggestion(int turn, int pone_points, int ptwo_points, int round_points)
{
  int total;	
  if(turn == 1)
    total = pone_points + round_points;
  else
    total = ptwo_points += round_points;
  if (total >= THRESHOLD)
    {
      cout<<"Player"<< turn <<" has gained enough points from this "
	  <<"round to win!"<<endl;
      cout<< endl;
      return true;
    }
  else
    return false;
}
