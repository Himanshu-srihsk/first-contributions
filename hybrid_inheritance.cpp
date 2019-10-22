//Hybrid Inheritance oops
#include <bits/stdc++.h>
using namespace std;
class student{
protected:
    int roll;
public:
    void get_num(int a){
    roll=a;
    }
    void set_num(){
    cout<<roll<<endl;
    }
};
class test:public student{
protected:
    int m1,m2;
public:
    void get_mark(int m1,int m2){
    this->m1=m1;
    this->m2=m2;
    }
    void set_marks(){
    cout<<m1<<" "<<m2<<endl;
    }
};
class sports{
protected:
    int score;
public:
    void get_score(int s){
    score=s;
    }
    void put_score(){
    cout<<score<<endl;
    }

};
class results:public test,public sports{
float total;
public:
    void display(void);
};
void results::display(void){
total=m1+m2+score;
set_num();
set_marks();
put_score();
cout<<"total Score="<<total<<endl;

}
int main(){
results r1;
r1.get_num(1234);
r1.get_mark(55,99);
r1.get_score(52);
r1.display();
}
