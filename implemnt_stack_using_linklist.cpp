
//implemnt_stack_using_linklist.cpp
#include <bits/stdc++.h>
using namespace std;
struct stacknode{
int data;
stacknode *next;
stacknode(int d){
data=d;
next=NULL;
}
};
class mystack{
private:
    stacknode *top;
public:
    void push(int);
    int pop();
    mystack(){
    top=NULL;
    }
};
void mystack::push(int x){
  stacknode *temp=new stacknode(x);
  if(top==NULL){
    top=temp;
  }else{
  temp->next=top;
  }
  top=temp;
}
int mystack::pop(){
    if(top==NULL)
        return -1;
int t=top->data;
top=top->next;
return t;
}
int main(){
int t;
cin>>t;
while(t--){
    int n,d;
    cin>>n;
    mystack *sq=new mystack();
     while (n--) {
            int QueryType = 0;
            cin >> QueryType;
            if (QueryType == 1) {
                int a;
                cin >> a;
                sq->push(a);
            } else if (QueryType == 2) {
                cout << sq->pop() << " ";
            }

        }
         cout << endl;

}
}
