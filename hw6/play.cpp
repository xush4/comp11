#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include "board.h"

using namespace std;
typedef int* IntArrayPtr;

int main()
{
  srand(time(0));
  Board *B;
  const int dimen=4;
  B=new Board(dimen);
  //B.set_dimen(4);
  B->init_board();
  B->print_board();
  //cout<< B.get_dimen()<<endl;
  //B->set_sum();
  cout<< B->get_sum()<<endl;
  //int *all_number=B->get_matrix();
  //int matrix1[dimen][dimen];
  // for (int i=0;i<dimen;i++)
  //  {
  //    for (int j=0; j<dimen;j++)
  //	{
  //	  matrix1[i][j]=all_number[i*dimen+j];
  //	}
  //}
  // for (int i=0;i<dimen;i++)
  // {
  //  for (int j=0; j<dimen;j++)
  //	{
  // if(matrix1[i][j]==0)
  //	    cout<<"x";
  //	  else
  //	    cout<< matrix1[i][j];
  //	  if(j==dimen-1)
  //	    cout<<endl;
  //	  else
  //	    cout<<' ';
  //	}
  //  }
  // cout<<endl;
  for(int i=0; i<2;i++){
    if (B->get_achar()!='q'){
  B->set_achar('w');
  char a=B->get_achar();
  cout<<a<<" Should be up"<<endl;
  B->make_move();
  B->print_board();
  //cout<< B->get_sum()<<endl;
    }

    if (B->get_achar()!='q'){
  B->set_achar('a');
  char a=B->get_achar();
  cout<<a<<" Should be left"<<endl;
  B->make_move();
  B->print_board();
  //cout<< B->get_sum()<<endl;
 }

 if (B->get_achar()!='q'){
  B->set_achar('s');
  char a=B->get_achar();
  cout<<a<<" Should be down"<<endl;
  B->make_move();
  B->print_board();
  //cout<< B->get_sum()<<endl;
 }

 if (B->get_achar()!='q'){  
  B->set_achar('d');
  char a=B->get_achar();
  cout<<a<<" Should be right"<<endl;
  B->make_move();
  B->print_board();
  //cout<< B->get_sum()<<endl;
 }
  }
}
