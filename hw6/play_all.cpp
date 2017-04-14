// Comp11
// HW7
// Main Function
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

using namespace std;
int main()
{
  //set random seed
  srand(time(0));
  Game G; 
  //Start and Initialize;
  G.start_game();
  //Make move until "q".
  G.next_move();
  //Game ends automatically
}
