/* COMP11
 * Spring 2017
 * HW5 
 * Sheng Xu*/

// 1.Output everything around 0
// in vicinity
// 2.Choose MAX_MINES;
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <sstream>
#include <string>
#include <stdio.h>

using namespace std;

const int DIMEN = 9;
//const int MAX_MINES = 25;
const string MINE = "x";
const string UNSEEN = "-";

// function prototypes
void print_board( string [][DIMEN]);
void populate_plain_board( string [][DIMEN]);
void populate_mines_board( string [][DIMEN], int);
void zeros( int [][DIMEN]);
// A function to emerge zeros around
void emerge_zero(string [][DIMEN], string [][DIMEN],
		 bool [][DIMEN], int, int);
void populate_appearboard(bool [][DIMEN]);

int main()
{
    srand(time(NULL));
    int a;
    do{
    cout << "Input how many mines you want?"
	 << " 16-30 is recommended."<< endl;
    cin >> a;
    }while(a<0 || a>(DIMEN*DIMEN-1));
    const int MAX_MINES =a;
    int not_mines = DIMEN*DIMEN-MAX_MINES;
    string user_board[DIMEN][DIMEN];
    string mines[DIMEN][DIMEN];
    bool appear[DIMEN][DIMEN];
    populate_plain_board(user_board);
    populate_mines_board(mines, MAX_MINES);
    populate_appearboard(appear);
    cout << "Let's play minesweeper!\n";
    print_board(user_board);
    bool game_on = true;
    while(game_on)
        {
	    int row_n, col_n;	
	    do
	        { 
		    cout << "Enter the row and column number of the"
			 << " square to uncover"
			 << endl;
		    cin >> row_n >> col_n;
		} while(row_n < 0 || col_n < 0 || row_n > DIMEN || 
			col_n>DIMEN || user_board [row_n] [col_n] != 
                        UNSEEN);
	    user_board [row_n] [col_n] = mines [row_n] [col_n];
	    emerge_zero(user_board, mines, appear, row_n, col_n);
	    print_board(user_board);
	    cout<< endl;
	    //print_board(mines);
	    if ( user_board[row_n][col_n] == MINE)
	      {
		game_on = false;
		cout << "Boom! Game Over!"<< endl;
	      }
	    else
	      not_mines--;
	    if (not_mines==0)
	      {
		cout << "Congratulations. You win!"<< endl;
		game_on = false;
	      }
	}
    return 0;
}
//Function: populate_appearboard
//Input: 2D array of bool
//Return Nothing
//Does: Set everything false
void populate_appearboard(bool board[][DIMEN])
{
  for (int i = 0; i < DIMEN; i++)
    {
      for(int j = 0; j < DIMEN; j++)
	board[i][j] = false;
    } 
}


//Function: zeros
//Input: 2D array of int
//Return Nothing
//Does: Set everything 0
void zeros(int board[][DIMEN])
{
  for (int i = 0; i < DIMEN; i++)
    {
      for(int j = 0; j < DIMEN; j++)
	board[i][j] = 0;
    } 
}
// Function: emerge_zero
// Input: 2D array of string
// Return Nothing
// Does: make all number around zero appear
void emerge_zero(string board[][DIMEN], 
		 string mines[][DIMEN], 
		 bool appear[][DIMEN],
		 int row_n, int col_n)
{
  bool zero_appear = true;
  //int a,b;
  int start_row = row_n-1;
  int end_row = row_n+1; 
  int start_col = col_n-1; 
  int end_col = col_n+1;
  if (board[row_n][col_n]=="0")
    zero_appear = false;
  else
    appear[row_n][col_n]=true;
  if (not zero_appear)
    {
      if (row_n == 0)
	start_row = 0;
      if (col_n == 0)
	start_col = 0;
      if (row_n == DIMEN-1)
	end_row = DIMEN-1;
      if (col_n == DIMEN-1)
	end_col=DIMEN-1;
      for (int k = start_row; k <= end_row; k++)
	{
	  for ( int j = start_col; j <= end_col; j++)
	    {
	      if ((not appear[k][j]))
		{
		  appear[k][j] = true;
		  board[k][j]=mines[k][j];
		  // Recursive
		  emerge_zero(board, mines, appear, k, j);
		}
	    }
	}
    }
}

// Function: populate_mines_board
// Input: 2d array of chars
// Returns: nothing
// Does: put the mines and number of mines around in all squares
void populate_mines_board(string board[][DIMEN], int MAX_MINES)
{
     int i = 0;
     // set a matrix to track number of mines.
     int num_mines[DIMEN][DIMEN];
     zeros( num_mines);
     //input mines
     while( i < MAX_MINES)
         {
	     int row_n, col_n;
	     row_n = rand()%DIMEN;
	     col_n = rand()%DIMEN;
	     //Set Mines
	     if (board[row_n][col_n] != MINE)
	         {
		     board[row_n][col_n] = MINE;
		     i++;
		     //set nunmber
		     int start_row = row_n-1;
		     int end_row = row_n+1; 
		     int start_col = col_n-1; 
		     int end_col = col_n+1;
		     if (row_n == 0)
		       start_row = 0;
		     if (col_n == 0)
		       start_col = 0;
		     if (row_n == DIMEN-1)
		       end_row = DIMEN-1;
		     if (col_n == DIMEN-1)
		       end_col=DIMEN-1;
		     for (int k = start_row; k <= end_row; k++)
		       {
			 for (int j = start_col; j <= end_col; j++)
			   {
			     num_mines[k][j]++;
			   }
		       }
		 }
	     for (int j = 0;j < DIMEN; j++)
	         {
		     for(int k = 0; k < DIMEN; k++)
		       {
			 if (board[j][k] != MINE)
			   {
			     //translate number to string.
			     stringstream ss;
			     ss << num_mines[j][k];
			     string s = ss.str();
			     board[j][k] = s;
			   }
		       }
		 }
	 }
}

// Function: populate_plain_board
// Input: 2d array of chars
// Returns: nothing
// Does: puts the UNSEEN char in all squares
void populate_plain_board(string board[][DIMEN])
{
    for (int i = 0; i < DIMEN; i++)
        for (int j = 0; j < DIMEN; j++)
            board[i][j] = UNSEEN;
}

// Function print_board
// Input: 2d array of chars
// Returns: nothing
// Does: Prints the given 2d array 
//		 as well as headers for indices
void print_board(string board[][DIMEN])
{
	cout << "  ";
    for (int i = 0; i < DIMEN; i++)
        cout << i << " ";
	cout << endl;

    for (int i = 0; i < DIMEN; i++)
    {
		cout << i << " ";
        for (int j = 0; j < DIMEN; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
