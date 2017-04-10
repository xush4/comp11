#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long factorial(int);

int main() {
    int N;
    cin>>N;
    cout<<factorial(N);
    return 0;
}

long long factorial(int N){
    if (N>1)
        return N*factorial(N-1);
    else
        return 1;
}

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   