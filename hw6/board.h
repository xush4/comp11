//HW 6 & 7
//Comp11
//Sheng Xu
//Sign of by

//Description:
//Class: board
//Fuction:
//initial
//sum
//print board
//add_number

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
        int sum;
	char next_step;//take char input
	               //w,a,s,d,e
	int *numbers;  //numbers of matrix
                       //stored in 1D
	//int num_zeros;
	//int *zero_position;
    public:
	
        // Constuctor & Destructor;
        Board(int new_dimen=4);
	~Board();

        // Setters and Getters
       
        void set_dimen(int input_dimen);// shouldn't be called
	void set_sum();
	void set_matrix(int *new_numbers);
	void set_achar(char char_input);

        int get_dimen();
        int get_sum();
	IntArrayPtr get_matrix();
	char get_achar();

	//Initialize
	void init_board();

	// make changes
	void make_move();
	void go_up();
	void go_left();
	void go_down();
	void go_right();

        // Output
        void print_board();
	
	// line up none_zeoro numbers & 
	// combine two same numbers
	// embedded into go_up; go_left; go_down
	// and go_right functions.
	void line_up(int []);
}; 

#endif
