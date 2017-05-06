// INput names, age, student_number
// 4 scores
// Calculate Average score.
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

class Student{
private:
  int age, score1, score2, score3, score4;
  char *name;
  char *num;
  int ave;
public:
  Student(char aname[], int aage, char anum[],
	  int ascore1, int ascore2, int ascore3,
	  int ascore4)
  {
    name=aname;
    age=aage;
    num=anum;
    score1=ascore1;
    score2=ascore2;
    score3=ascore3;
    score4=ascore4;
  }
  void set_Ave()
  {
    ave=0.25*(score1+score2+score3+score4);
  }
  char *getName()
  {
    return name;
  }
  int getAge()
  {
    return age;
  }
  char *getNum()
  {
    return num;
  }
  void get_inf()
  {
    set_Ave();
    cout<<name<<","<<age<<","
	<<num<<","<<ave<<endl;
  }

};

int main(){
  char name[100], num[100];
  int age, score1,score2,score3,score4;
  cin.getline(name, 100, ',');
  char a;
  cin>>age>>a;
  cin.getline(num,100,',');
  cin>>score1>>a>>score2>>a>>score3>>a>>score4;
  cout<<score1<<" "<<score2<<" "<<score3<<" "<<score4<<endl;
  Student s(name,age,num,score1,score2,score3,score4);
  s.get_inf();
  return 0;
}
