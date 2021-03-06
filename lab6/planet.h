#include <iostream>
#include <string>
using namespace std;

#ifndef PLANET_H_
#define PLANET_H_

class Planet
{
  private:
	// Attributes of a planet, always private
    string name;
    int num_moons;
    double distance;
    double diameter;

  public:
	// Constructor
	Planet();

	// Setters and getters
	string get_name();
	int get_num_moons();
	double get_distance();
	double get_diameter();

	void set_name(string);
	void set_num_moons(int);
	void set_distance(double);
	void set_diameter(double);
	// Print a nicely-formatted version of the planet's data
    void print_data();
};

#endif
