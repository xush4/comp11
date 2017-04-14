// Comp11
// HW7
// Class board
// Sheng Xu

//Additioanal score included.

//Five documents included: board.h game.h play_all.cpp
//                         board.cpp game.cpp

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include "board.h"

using namespace std;
typedef int* IntArrayPtr;

// Constructor & Destructor
Board::Board()
{
  dimen = 1;
  sum =0;
  next_step='0';
  //numbers = NULL;
  myMatrix=new IntArrayPtr [dimen];
  for(int i=0 ; i<dimen;i++)
    myMatrix[i]=NULL;
  for(int i=0;i<4;i++)
    rec[i]=i+1;
  rec[4]=4;
  direction[0]="up";//0-w-up 1-a-l 2-s-d 3-d-r
  direction[1]="left";
  direction[2]="down";
  direction[3]="right";
  top_rec="up";
}

Board::Board(int new_dimen)
{
  dimen = new_dimen;
  sum = 0;
  next_step = '1';// 1 for start game; q for end game
  //numbers = new int[dimen*dimen];
  myMatrix= new IntArrayPtr [dimen];
  for (int i=0; i<dimen;i++)
    myMatrix[i]= new int [dimen];
  for(int i=0;i<4;i++)
    rec[i]=i+1;
  rec[4]=4;
  //num_zeros=dimen*dimen;
  //zero_position=new int[dimen*dimen];
  direction[0]="up";//0-w-up 1-a-l 2-s-d 3-d-r
  direction[1]="left";
  direction[2]="down";
  direction[3]="right";
  top_rec="up";
}

Board::~Board() 
{
  //  delete numbers;
  for(int i=0; i<dimen;i++)
    if(myMatrix[i]!=NULL)
      delete[] myMatrix[i];
  delete[] myMatrix;
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

void Board::set_sum(int a)
//  shouldn't be called in this program.
{
  sum=a;
}

int Board::get_sum() //Return Score
{
  return sum;
}

void Board::set_matrix (int *new_numbers)
// left to set NULL
{
  for(int i=0; i<dimen;i++)
    myMatrix[i]= new_numbers;
}

void Board::set_matrix2 (int new_numbers[])
// set matrix with array
{
  for (int i = 0;i < dimen;i++)
    for(int j = 0;j < dimen;j++)
      myMatrix[i][j] = new_numbers[i*dimen+j];
}

IntArrayPtr *Board::get_matrix2()
{
  return myMatrix;
}

void Board::set_achar(char char_input)
// set move
{
  next_step=char_input;
}

char Board::get_achar()
{
  //cout<<next_step;  
  return next_step;
}

void Board::set_rec(string a)
// set recommendation
{
  top_rec=a;
}

string Board::get_rec()
// return recommendation
{
  return top_rec;
}

// Initialize
void Board::init_board()
// put 2 two in board, zero to others.
{
  const int New_Dimen = get_dimen();
  for (int i = 0;i < dimen;i++)
    for(int j = 0;j < dimen;j++)
      myMatrix[i][j] = 0;
  myMatrix[New_Dimen-1][New_Dimen-2] = 2;
  myMatrix[New_Dimen-2][New_Dimen-1] = 2;
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

  add_anum();
  Calculate_Recommendation();
  Make_Recommendation();
  //cout<<rec[4]<<endl;
}

void Board::go_up()
{
  //set matrix
  int matrix1[dimen][dimen];
  const int New_Dimen2 = get_dimen();
  for (int i = 0;i < dimen;i++)
    for(int j = 0;j < dimen;j++)
      matrix1[i][j] = myMatrix[i][j];

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
      {
	//numbers[i*New_Dimen2+j] = matrix1[i][j];
	myMatrix[i][j]=matrix1[i][j];
      }
}

void Board::go_down()
{
  //set matrix
  int matrix1[dimen][dimen];
  const int New_Dimen2 = get_dimen();
  for (int i = 0;i < dimen; i++)
    for(int j = 0;j < dimen; j++)
      matrix1[i][j] =  myMatrix[i][j];
  
  // put non-zero to botton
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
      {
	//numbers[i*New_Dimen2+j] = matrix1[i][j];
	myMatrix[i][j]=matrix1[i][j];
      }
}

void Board::go_left()
{
  //set matrix
  int matrix1[dimen][dimen];
  const int New_Dimen2 = get_dimen();
  for (int i = 0; i < dimen; i++)
    for(int j = 0; j < dimen; j++)
      matrix1[i][j] = myMatrix[i][j];

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
      {
	//numbers[i*New_Dimen2+j] = matrix1[i][j];
	myMatrix[i][j]=matrix1[i][j];
      }
}

void Board::go_right()
{
  //set matrix
  int matrix1[dimen][dimen];
  const int New_Dimen2 = get_dimen();
  for (int i = 0; i < dimen; i++)
    for(int j = 0; j < dimen; j++)
      matrix1[i][j] =  myMatrix[i][j];

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
      {
	//numbers[i*New_Dimen2+j] = matrix1[i][j];
	myMatrix[i][j]=matrix1[i][j];
      }
}

void Board::add_anum()
{
  //90% 2; 10% 4
  int add_number = 2;
  int rand_number = rand()%10;
  if (rand_number == 1)
    add_number = 4;
  int zeros[dimen*dimen];
  int num_zero = 0;
  int new_numbers[dimen*dimen];
  for (int i = 0;i < dimen; i++)
    for(int j = 0;j < dimen; j++)
      new_numbers[i*dimen+j] =  myMatrix[i][j];
  for (int i = 0; i < dimen*dimen; i++)
    {
      if (new_numbers[i] == 0)
	{
	  zeros[num_zero] = i;
	  num_zero++;
	}
    }
  if (num_zero==0)
    {
      cout<< "You can't make this move!"<<endl;
    }
  else
    {
      int place = rand()%(num_zero);
      //numbers[zeros[place]] = add_number;
      new_numbers[zeros[place]] = add_number;
      set_matrix2(new_numbers);
      //set_sum();
    }
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
  for (new_col = 1; new_col < k; new_col++)
	{
	  if (arr[new_col] == arr[new_col-1] 
	      && arr[new_col]!=0)
	    {
	      sum+=(arr[new_col]*2);
	      arr[new_col-1] *= 2;
	     
	      for(int i = new_col; i < k; i++)
	        arr[i]=arr[i+1];
	      //new_col--;
	      k--;
	    }
      }
}

void Board::Calculate_Recommendation()
{
  int origin_number[dimen*dimen];
  for (int i = 0;i < dimen;i++)
  for(int j = 0;j < dimen;j++)
  origin_number[i*dimen+j]=myMatrix[i][j];
  int origin_sum=sum;
  int available_move=0;// Number of directions 
                       // we can use in next step 
  int rank[4];// 0-w-up 1-a-l 2-s-d 3-d-r
  int num_zero[4];
  for (int i=0; i<4;i++)
    {
      rank[i]=i+1;
      num_zero[i]=0;
    }
  for (int j=0; j<4; j++)
    {
      if (j==0)
	go_up();
      if (j==1)
	go_left();
      if (j==2)
	go_down();
      if (j==3)
	go_right();
  
      for (int i = 0; i < dimen; i++)
	{
	  for (int k=0;k<dimen;k++) 
	    {
	      if (myMatrix[i][k] == 0)
		{
		  //Find num of zeors
		  num_zero[j]++;
		}
	    }
	}
      if (num_zero[j]>0)
	available_move++;
      set_matrix2(origin_number);
      set_sum(origin_sum);
    }

  //Rank Directions.
  for(int i=0; i<4; i++){
    for(int j=i+1; j<4; j++){
      int change_same=rand()%2;
      if (num_zero[j]>num_zero[i]
	  || (num_zero[i]==num_zero[j] && change_same==1))
	{
	  int temp1=num_zero[j];
	  num_zero[j]=num_zero[i];
	  num_zero[i]=temp1;
	  int temp2=rank[j];
	  rank[j]=rank[i];
	  rank[i]=temp2;
	}
    }
  }
  for(int i=0; i<4; i++)
    {
      rec[i]=rank[i];
    }
  rec[4]=available_move;
  top_rec=direction[rec[0]-1];
}

void Board::Make_Recommendation()
{
  if (rec[4]==0)
    {
      next_step = 'q';
      cout<< "End of Game! "<<endl;
    }
      else 
    {
      cout<<"There are "<<rec[4]<<" move(s) available: "
	  <<endl; 
      for (int i=0; i<rec[4]; i++)
	  cout<< direction[rec[i]-1]<<" ";
      cout<<endl;
    }
}

//Output
void Board::print_board()
{
  cout<<"Your Score is "<<sum<<"."<<endl;
  const int New_Dimen2 = get_dimen();
  for (int i=0; i<dimen; i++)
    {
      for (int j=0; j<dimen; j++)
	{
	  if(myMatrix[i][j] == 0)
	    cout<<"x   ";
	  else
	    {
	      cout<< myMatrix[i][j];
	      int k = 4;
	      int a = myMatrix[i][j];
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
	      for(int space = 0; space < 3; space++)
		cout<< endl;
	    }
	  else
	    cout<< ' ';
	}
    }
}


