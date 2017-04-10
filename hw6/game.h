//HW 6 & 7
//Comp11
//Sheng Xu
//Sign of by

//Description:
//Class: game
//Fuction:
//Start_game
//End_game
//next_step: Take an order


#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <board.h>

using namespace std;

#ifndef GAME_H_
#definr GAME_H_

class Game
{
    private:
        Board *board = new Board;
	char order;
	char FILE_NAME;
	int sum;
    public:
	void set_board();
	void start_game();
	void next_move();
	void end_game();
}


#endif