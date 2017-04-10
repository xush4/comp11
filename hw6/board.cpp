// Comp11
// HW7
//Class board
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include "board.h"
// Set defaulted value

using namespace std;
typedef int* IntArrayPtr;

// Constructor & Destructor
Board::Board(int new_dimen)
{
  dimen = new_dimen;
  sum = 0;
  next_step = '0';// 0 for start game; e for end game
  numbers = new int[dimen*dimen];
  //num_zeros=dimen*dimen;
  //zero_position=new int[dimen*dimen];
}

Board::~Board() 
{
  delete[] numbers;
  //delete[] zero_position;
}

// Setters & getters.

void Board::set_dimen(int input_dimen)
// shouldn't be called in this program.
{
  dimen = input_dimen;
}

int Board::get_dimen()
{
  return dimen;
}

void Board::set_sum()
{
  sum = 0;
  for (int i = 0; i < dimen*dimen; i++)
    {
      sum += numbers[i];
    }
}

int Board::get_sum()
{
  return sum;
}

void Board::set_matrix (int *new_numbers)
//void Board::set_matrix (vector<vector<int> >new_numbers)
{
  numbers = new_numbers;
}

IntArrayPtr Board::get_matrix()
{

  return numbers;
}

void Board::set_achar(char char_input)
{
  next_step=char_input;
}

char Board::get_achar()
{
  //cout<<next_step;  
  return next_step;
}

// Initialize
void Board::init_board()
{
  const int New_Dimen = get_dimen();
  for (int i = 0;i < New_Dimen*New_Dimen; i++)
    {
      numbers[i] = 0;
      //zero_position[i]=i;
    }
  numbers[New_Dimen*New_Dimen-2] = 2;
  //for (int i=New_Dimen*New_Dimen-2; i<dimen*dimen;i++)
  //  zero_position[i]=zero_position[i+1];
  numbers[New_Dimen*(New_Dimen-1)-1] = 2;
  //for (int i=New_Dimen*(New_Dimen-1)-1; i<dimen*dimen;i++)
  //  zero_position[i]=zero_position[i+1];
  //num_zeros-=2;
}

// Make changes
void Board::make_move()
{
  if (next_step == 'w')
    go_up();
  else if (next_step == 'a')
    go_left();
  else if (next_step == 's')
    go_down();
  else if (next_step == 'd')
    go_right();
  int add_number = 2;
  int rand_number = rand()%10;
  if (rand_number == 1)
    add_number = 4;
  int zeros[dimen*dimen];
  int num_zero = 0;
  for (int i = 0; i < dimen*dimen; i++)
    {
      if (numbers[i] == 0)
	{
	  zeros[num_zero] = i;
	  num_zero++;
	}
    }
  if (num_zero == 0)
    next_step = 'e';
  else 
    {
  int place = rand()%(num_zero);
  numbers[zeros[place]] = add_number;
  set_sum();
    }
}

void Board::go_up()
{
  //set matrix
  int matrix1[dimen][dimen];
  const int New_Dimen2 = get_dimen();
  for (int i = 0;i < dimen;i++)
    for(int j = 0;j < dimen;j++)
      matrix1[i][j] = numbers[i*New_Dimen2+j];

  // put non-zero to top
  int row, col, new_row, new_col;
  for (col = 0;col < New_Dimen2; col++)
    {
      int arr [New_Dimen2+1];
      for(int i = 0;i < New_Dimen2; i++)
	arr[i] = matrix1[i][col];
      arr[New_Dimen2] = 0;
      line_up(arr);
      for(int i = 0; i < New_Dimen2; i++)
	matrix1[i][col] = arr[i];
    }
  // update
  for (int i = 0;i < dimen; i++)
    for(int j = 0;j < dimen; j++)
      numbers[i*New_Dimen2+j] = matrix1[i][j];
}

void Board::go_down()
{
  //set matrix
  int matrix1[dimen][dimen];
  const int New_Dimen2 = get_dimen();
  for (int i = 0;i < dimen; i++)
    for(int j = 0;j < dimen; j++)
      matrix1[i][j] = numbers[i*New_Dimen2+j];
  
  // put non-zero to top
  int row, col, new_row, new_col;;
  for (col = 0; col < New_Dimen2; col++)
    {
      int arr [New_Dimen2+1];
      for(int i = 0;i < New_Dimen2; i++)
	arr[i] = matrix1[New_Dimen2-1-i][col];
      arr[New_Dimen2] = 0;
      line_up(arr);

      //update matrix
      for(int i = 0;i < New_Dimen2; i++)
	matrix1[New_Dimen2-1-i][col] = arr[i];
    }

  // update numbers
  for (int i = 0;i < dimen;i++)
    for(int j = 0;j < dimen;j++)
      numbers[i*New_Dimen2+j] = matrix1[i][j];
}

void Board::go_left()
{
  //set matrix
  int matrix1[dimen][dimen];
  const int New_Dimen2 = get_dimen();
  for (int i = 0; i < dimen; i++)
    for(int j = 0; j < dimen; j++)
      matrix1[i][j] = numbers[i*New_Dimen2+j];
  // put non-zero to left
  int row, col, new_row, new_col;
  for (row = 0;row < New_Dimen2; row++)
    {
      int arr [New_Dimen2+1];
      for(int i=0; i<New_Dimen2; i++)
	arr[i]=matrix1[row][i];
      arr[New_Dimen2]=0;
      line_up(arr);

      //update matrdix
      for(int i = 0; i < New_Dimen2; i++)
        matrix1[row][i] = arr[i];
      // k=0;
    }

  //update numbers
  for (int i = 0; i < dimen; i++)
    for(int j = 0; j < dimen; j++)
      numbers[i*New_Dimen2+j] = matrix1[i][j];
}

void Board::go_right()
{
  //set matrix
  int matrix1[dimen][dimen];
  const int New_Dimen2 = get_dimen();
  for (int i = 0; i < dimen; i++)
    for(int j = 0; j < dimen; j++)
      matrix1[i][j] = numbers[i*New_Dimen2+j];

  // put non-zero to Right
  int row, col, new_row, new_col;

  for (row = 0;row < New_Dimen2; row++)
    {
      int arr [New_Dimen2+1];
      for(int i=0; i<New_Dimen2; i++)
	arr[i] = matrix1[row][New_Dimen2-i-1];
      arr[New_Dimen2] = 0;
      line_up(arr);
      // update matrix
      for(int i = 0;i < New_Dimen2; i++)
	matrix1[row][New_Dimen2-i-1] = arr[i];
    }
  //update numbers
  for (int i = 0; i < dimen; i++)
    for(int j = 0; j < dimen; j++)
      numbers[i*New_Dimen2+j] = matrix1[i][j];
}

void Board::line_up(int arr[])
{
  const int New_Dimen2 = get_dimen();
  int row, col, new_row, new_col;
  int k=0;
  for (col = 0;col < New_Dimen2; col++)
	{
	if (arr[col] != 0 & col != k)
	  {
	    arr[k] = arr[col];
	    arr[col] = 0;
	    k++;
	  }
	else if (arr[col] != 0 & col == k)
	  {
	    k++;
	  }
	}
  for (new_col = 1; new_col <= k; new_col++)
	{
	  if (arr[new_col] == arr[new_col-1])
	    {
	      arr[new_col-1] *= 2;
	      for(int i = new_col; i < k; i++)
	        arr[i]=arr[i+1];
	      //new_col--;
	      k--;
	    }
      }
}

//Output
void Board::print_board()
{
  const int New_Dimen2 = get_dimen();
  // IntArrayPtr new_numbers=get_matrix();
  for (int i=0; i<dimen; i++)
    {
      for (int j=0; j<dimen; j++)
	{
	  if(numbers[i*New_Dimen2+j] == 0)
	    cout<<"x   ";
	  else
	    {
	      cout<< numbers[i*New_Dimen2+j];
	      int k = 4;
	      int a = numbers[i*New_Dimen2+j];
	      while (a > 0)
		{
		  k--;
		  a = a/10;
		}
	      for (int space = 0; space<k; space++)
		{
		  cout<<" ";
		}
	    }
	  if(j == dimen-1)
	    {
	      for(int space = 0; space < 4; space++)
		cout<< endl;
	    }
	  else
	    cout<< ' ';
	}
    }
}


