//HW 6 & 7
//Comp11
//Sheng Xu
//Sign of by Liana McClintock on april 11th 

//additioanal score included.

//four documents included: board.h game.h
//                         board.cpp game.cpp

//Description:
//Class: game
//Fuction:
//Start_game
//next_move: Take an order
//scores: group by dimensions and rank descending
//read_high_score; write_in_file

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include "board.h"

using namespace std;

#ifndef GAME_H_
#define GAME_H_

class Game
{
  
 private:
  
  Board *B;
  int dimen; //valid input: 3 to 9;
  char end_G; // change to q and game over;
  //string FILE_NAME;

 public:
  //constructer
  Game();
  ~Game();

  //getters and setters;
  char get_Gchar();    //set and get end_G
  void set_Gchar(char char_input);

  int get_dimen();
  void set_dimen(int);

  //Game Functions
  void start_game();// Initialize
  void next_move();// main function: ask player to input a string
                   // and do corresponding thing.
  void read_high_score();//output according to current dimension
  void write_in_file(int, string, int); // input: Dimension name score
};

#endif
