#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    map<string,string> phone_book;
    string name, tel;
    while(n--){
        cin>>name>>tel;
        phone_book.insert(make_pair(name,tel));
    }
    while(cin>>name){
        map<string, string>::iterator p = phone_book.find(name);
        if(p != phone_book.end())
            cout<<p->first<<"="<<p->second;
        else
            cout<<"Not found";
        cout<<endl;
    }
    return 0;
}