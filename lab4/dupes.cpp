/* COMP11
 * Spring 2017
 * Lab 4 - Starter Code */

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

// constant for array capacity
const int MAX = 20;

// function prototypes 
void populate(int []);
void print_array(int [], int);
int dedupe(int [], int[], int);

int main()
{
	// Random-number seed
    srand(time(NULL));

	// Declare an array of ints
	// and populate it.
    int ray_dupes[MAX];
    populate(ray_dupes);
    int count[MAX];
    for(int i=0;i<MAX;i++)
      count[i]=1;
	// Print the array so we know the starting point
    print_array(ray_dupes, MAX);
    const int new_max = dedupe(ray_dupes, count, MAX);
    //cout << new_max;
    print_array(ray_dupes, new_max);
    //print_array(count,new_max);
    cout<<"There were ";
    int dupe_count=0;
    for (int i=0;i<new_max;i++)
      {
	if (count[i]>1)
	  {
	    dupe_count++;
	    cout<< count[i]<<" "<<ray_dupes[i]<<"s, ";
	  }
      }
    cout<<endl;
    cout<< "Found "<<dupe_count<<" duplicated numbers."<<endl;
    return 0;
}

int dedupe(int arr[], int count[], int MAX)
{
  int i, j, k;
  int size=MAX;
  for (i=0; i<size; i++)
    {
      for (j=i+1; j<size; j++)
	{
	  if (arr[j]==arr[i])
	    {
	      for (k=j;k<size;k++)
		{
		  arr[k]=arr[k+1];
		  
		}
		size--;
		j--;
		count[i]++;
		// cout << size<<" "<<endl;
	    }
	}
    }
  return size;
}

// Function populate
// Input: array of ints
// Returns: nothing
// Does: populates the array with
// 		 random numbers
void populate(int ray[])
{
    int r;
    if (MAX>=3)
      { 
	for(int i = 0; i < MAX; i++)
	  {
      
	    r = rand() % MAX * 2 / 3;
	    ray[i] = r;
	  } 
      }     
      // duplicate guaranteed when max>=3;
    else if (MAX==2)
      {
	r = rand() % 2;
	ray[1] = r;
	ray[2] = r;
      }
}

// Function print_array
// Input: array of ints, size of array
// Returns: nothing
// Does: prints array elements
void print_array(int ray[], int size)
{
    for(int i = 0; i < size; i++)
        cout << ray[i] << " ";
    cout << endl;
}
