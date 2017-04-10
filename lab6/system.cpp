// COMP11
// LAB6
// SHENG XU Daniel Le Breton
// APRIL 4, 2017

// Add another attributes: diameter;
// Rank the planets according to the
// distance from sun ascending; 
#include <iostream>
#include "planet.h"

int main()
{
  int num_planet;
  // input number of planets
  cout<< "How many planets do you think there are?"<<endl;
  cin>>num_planet;

  //dynamically allocate array of planets
  Planet *planets = new Planet [num_planet];

  //input information with for loop
  for (int i=0; i<num_planet; i++)
    {
      cout<<"What is the name of planet "<<i+1<<"?"<<endl;
      string name_planet;
      cin>>name_planet;
      planets[i].set_name(name_planet);

      cout<<"How many moons does it have?" <<endl;
      int num_moons;
      cin >> num_moons;
      planets[i].set_num_moons(num_moons);

      cout<<"How far from the sun, in millions of miles?" <<endl;
      double num_miles;
      cin >> num_miles;
      planets[i].set_distance(num_miles);

      cout<<"How long is the diameter of the planet"<<endl;
      double num_dia;
      cin>>num_dia;
      planets[i].set_diameter(num_dia);
      // planets[i].print_data();
    }

  //output information
  cout<<"Thank you for input!"<<endl;
  cout<<"Here are all the planets:"<<endl;
  double distance[num_planet];
  int rank[num_planet];
  for (int i=0; i< num_planet;i++){
    distance[i]=planets[i].get_distance();
    rank[i]=i;
  }
  
  //rank planets according to the distance from sun
  for (int i=0; i<num_planet;i++){
    for(int j=i+1; j<num_planet; j++){
      if (distance[j]<distance[i])
	{
	  double temp_dist=distance[i];
	  distance[i]=distance[j];
	  distance[j]=temp_dist;
	  int temp_rank=rank[i];
	  rank[i]=rank[j];
	  rank[j]=temp_rank;
	}
    }
  }

  for (int i=0; i< num_planet;i++)
    {
      int temp_rank = rank[i]; 
     planets[temp_rank].print_data();
    }
  return 0;
}
