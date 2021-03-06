// Comp11
// HW7
// class game
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
#include "game.h"
#include <fstream>

using namespace std;

// Constructor & destructor
Game::Game()
{
  dimen=0;
  B=NULL;
  end_G='0';
}

Game::~Game()
{
  if (B!=NULL)
    B->set_matrix(NULL);
  B->~Board();
}

char Game::get_Gchar()
{
  return end_G;
}

void Game::set_Gchar(char char_input)
{
  end_G=char_input;
}

int Game::get_dimen()
{
  return dimen;
}

void Game::set_dimen(int num)
{
  dimen=num;
}

void Game::start_game()
{
  cout<< "Please enter the size of Board(3~9)"<<endl;
  cin >> dimen;
  // dimension between 2 and 8 (inclusive)
  while(dimen<=2 || dimen>9)
    {
      cout<< "Invalid Size! Please Re-enter..."<<endl;
      cout<< "Please enter the size of Board?"<<endl;
      cin >> dimen;
    }
  read_high_score();
  B = new Board(dimen);
  //FILE_NAME="HIGH_SCORE.txt";
  end_G=B->get_achar();
  B->init_board();
  B->print_board();
}

void Game::next_move()
// make move until end game: end_G=='q'.
{
  char amove;
  while(end_G!='q')
    {
      do{
	cout<<"Please Enter Your Next Move!"<<endl;
	cout<<"w for up; s for down; a for left; d for right. "
	    <<"q for quit"<<endl;
	cout<<"r for recommendation. h for high scores."<<endl;;
	cin>>amove;
      }while(amove!='w' && amove!='a' && amove!='s' &&
	     amove!='d' && amove!='h' && amove!='q' && amove!='r');
      cout<<endl;
      // update and print board
      if (amove=='w' || amove =='a'|| amove=='s'|| amove=='d')
	{
	  B->set_achar(amove);
	  B->make_move();
	  B->print_board();
	}
      if (amove=='r')
	{
	  cout<<"AI recommends: "<<B->get_rec()<<endl;
	  cout<<endl;
	}
      if (amove=='q')
	B->set_achar(amove);
      if (amove=='h')
	read_high_score();
      set_Gchar(B->get_achar());
    }
  // End Game
  cout<<"End of Game! You got "<< B->get_sum()<<" Points!"<<endl;
  int score= B->get_sum();
  cout<<"Please Enter Your Name: ";
  string player_name;
  cin>>player_name;
  write_in_file(dimen, player_name, score);
  read_high_score();
}

void Game::read_high_score()
{
  const char* FILE_NAME="HIGH_SCORE.txt";  
  cout<< "High Scores: "<<dimen<<"*"<<dimen
      <<" Game"<<endl;
  ifstream infile;
  infile.open(FILE_NAME);
  if (!infile.is_open())
    {
      cerr<< "You're the first to play this game!"<<endl;
      infile.clear();
    }
  else
    {
      int high_score[5];
      string player_name[5];
      int ctr=0;
      while (!infile.eof() && ctr<5)
	{
	  int dimen_number;
	  infile >> dimen_number;
	  if (dimen_number==dimen)
	  {
	      infile >> player_name[ctr];
	      infile >> high_score[ctr];
	      ctr++;
	  }
	  else
	    {
	      string a;
	      int b;
	      infile >> a;
	      infile >> b;
	    }
	}
      if (ctr>0)
	{
	  for (int i=0; i<ctr; i++)
	    cout<< player_name[i]<<" "<<high_score[i]<<endl;
	}
      else
	cout<< "You are the first to play this game in "<<dimen
	    <<"D!"<<endl;
	  infile.close();
    }
  cout<<endl;
}


void Game::write_in_file(int game_dimen, string current_player_name, 
			 int score)
// write scores into document
// sorry for a long function, cannot make it shorter.
{
  const char* FILE_NAME="HIGH_SCORE.txt";
  ofstream outfile;
  ifstream infile;
  infile.open(FILE_NAME);
  //cout<< "strat"<< infile.peek()<<"End"<<EOF<<endl;
  if (!infile.is_open())
    {
      cerr<< "You're the first to play this game!"<<endl;
      infile.close();
      infile.clear();
      outfile.open(FILE_NAME);
      outfile << game_dimen << " "<<current_player_name 
	      <<" "<<score;
      outfile.close();
    }

  else
    {
      vector<int > dimensions;
      vector<string > player_names;
      vector<int > scores;
      int dimen_number;
      string player_name;
      int high_score;
      int num_players=0;
      bool write_score=false;
      while (!infile.eof())
	{
	  infile >> dimen_number;
	  infile >> player_name;
	  infile >> high_score;
	  dimensions.push_back(dimen_number);
	  player_names.push_back(player_name);
	  scores.push_back(high_score);
	  num_players++;
	}
      infile.close();
      infile.clear();
      outfile.open(FILE_NAME);
      for (int i=0; i<num_players; i++)
	{
	  if (!write_score)
	    {
	      if (game_dimen<dimensions[i])
		{
		  outfile << game_dimen << " "<<current_player_name 
			  <<" "<<score<<endl;
		  write_score=true;
		}
	      else if (game_dimen==dimensions[i] && 
		       score>=scores[i])
		{
		  outfile << game_dimen << " "<<current_player_name 
			  <<" "<<score<<endl;
		  write_score=true;
		}
	    }
	  outfile << dimensions[i] << " "<<player_names[i] 
		  <<" "<<scores[i];
	  if (i!= num_players-1)
	    outfile << endl;
	}
      if (!write_score)
	{
	  outfile << endl<< game_dimen << " "<< current_player_name 
		  <<" "<<score;
	}
      //Release memory of Vectors: vector<int>().swap(s);
      vector<int>().swap(dimensions);
      vector<string>(). swap(player_names);
      vector<int>(). swap(scores);
    }
}
