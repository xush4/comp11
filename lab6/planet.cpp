#include "planet.h"

// Default constructor
Planet::Planet()
{
    name = "";
    num_moons = 0;
    distance = 0;
    diameter=0;
}

// Getters. Return values.
string Planet::get_name()
{
    return name;
}

int Planet::get_num_moons()
{
    return num_moons;
}

double Planet::get_distance()
{
    return distance;
}

double Planet::get_diameter()
{
    return diameter;
}
// Setters. Check for reasonable values.
// If unreasonable, stick with defaults.
void Planet::set_name(string n)
{
    if (n != "")
        name = n;
}

void Planet::set_num_moons(int n)
{
    if (n >= 0)
        num_moons = n;
}

void Planet::set_distance(double d)
{
    if (d >= 0)
        distance = d;
}

void Planet::set_diameter(double dia)
{
    if (dia >= 0)
        diameter = dia;
}

// Print all the planet's info
void Planet::print_data()
{
    cout << "Name: " << name << endl;
    cout << "Number of moons: " << num_moons << endl;
    cout << "Distance from the sun: " 
         << distance << " million miles\n";
    cout << "Diameter of the planet: "
	 << diameter << " thousand miles\n";
}
