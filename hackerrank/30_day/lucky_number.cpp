#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */

int get_length(long long int x);
int isPrime(long long int p);
long long int luckyNumbers(long long int a,long long int b) {
   long long int ans=0;
   
   for (long long int i=a; i<=b; i++)
   {
       long long int sum1=0;
       long long int sum2=0;
       long long int number=i;
       long long int len=get_length(number);
       for (int j=0; j<len; j++)
            {
            sum1+=number%10;
            sum2+=pow(number%10,2);
	   
            number=number/10;
        }
       ans= ans + isPrime(sum1)*isPrime(sum2);
       //cout<< i <<" "<< sum1 <<" "<< sum2<<endl;
   }
    
   return ans;
}


int get_length(long long int x)
{  
    using namespace std;  
    int leng=0;  
    while(x)  
    {  
        x/=10;  
        leng++;  
    } 
    //cout<< leng<<endl;
    return leng;  
}  



int  isPrime(long long int p)
{      
 long long int i;
 for (i=2;i<=sqrt((double)p);i++)
 {
    if(p%i==0)
     return 0 ;
 }
     return 1 ;      
}

/* Tail starts here */
int main() {
    long long int res;
   
    int _cases,_a_i;
    long long int _a,_b;
    scanf("%d", &_cases);
    
    for(_a_i = 0; _a_i < _cases; _a_i++) { 
        scanf("%lld %lld", &_a,&_b);
       res = luckyNumbers(_a,_b);    
        printf("%lld\n",res);
    }
    return 0;
}
