#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int arr[6][6];
    for(int arr_i = 0;arr_i < 6;arr_i++){
       for(int arr_j = 0;arr_j < 6;arr_j++){
          cin >> arr[arr_i][arr_j];
       }
    }
    int max;
    for(int i=1;i<5;i++){
        for(int j=1;j<5;j++){
            int  sum = arr[i-1][j-1]+ arr[i-1][j]+arr[i-1][j+1]
               +arr[i][j]+arr[i+1][j-1]+ arr[i+1][j]+arr[i+1][j+1];
            if(i==1 & j==1)
                max=sum;
            else if (sum>max)
                max=sum;
        }
    
    }
    cout<<max;
    return 0;
}