//HW 6 & 7
//Comp11
//Sheng Xu
//Sign of by Liana McClintock on april 11th 

//Additioanal score included.

//Five documents included: board.h game.h play_all.cpp
//                         board.cpp game.cpp

//Description:
//Class: board
//Fuction:
//initial
//make_move:up/down/left/right/line_up
//print board
//add_number
//recomend: additional score

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

#ifndef BOARD_H_
#define BOARD_H_

typedef int* IntArrayPtr;

class Board
{
    private:
        int dimen;
        int sum;       //current score;
	char next_step;//take char input
	               //w,a,s,d,e
	//int *numbers;  //numbers in matrix
                       //stored in 1D
	int rec[5];    //Store list of recomendation
	               //First four numbers are the sequence 
	               //of recommendation
	               //Last number is available moves.
	               //End game with 0 available move. 

	string direction[4];//Store list of direction
	string top_rec; //Top Recommendation.
	IntArrayPtr *myMatrix; //numbers in board
	                       //stored in 2D
	//int num_zeros;
	//int *zero_position;
    public:
	
        // Constuctor & Destructor;
	Board();
        Board(int);
	~Board();

        // Setters and Getters
       
        void set_dimen(int input_dimen);// shouldn't be called
	void set_sum(int );//set scores, shouldn't be called
	void set_matrix(int *new_numbers);// used to set arrays
	void set_matrix2(int []);// used to set whole matrix
	void set_achar(char char_input);// set next_step
	void set_rec(string a);//shouldn't be called

        int get_dimen();
        int get_sum();//get scores
	IntArrayPtr get_matrix1();//read matrix into a
	                          //dimen*dimen long array
	IntArrayPtr *get_matrix2();
	char get_achar();// get next_step
	string get_rec();// Get recommendation

	//Initialize
	void init_board();

	// make changes
	void make_move();
	//sub-functions for make_move
	void go_up();
	void go_left();
	void go_down();
	void go_right();
	void add_anum();// Add a number 
                        // or tell the player his move is invalid.

	// calculate available move and make recommendation
	// recommend by getting more zeros
	void Calculate_Recommendation();
	void Make_Recommendation();

        // Output
        void print_board();
	
	// put none_zeoro numbers to top& combine two same numbers
	// embedded into go_up; go_left; go_down
	// and go_right functions.
	void line_up(int []);
}; 

#endif
