
//DYnamic constructors Object oriented Programming

#include <bits/stdc++.h>
using namespace std;
class String{
char *str;
int len;
public:
    String(){
      len=0;
      str=new char[len+1];
    }
    String(char *s){
        delete str;
    len=strlen(s);
    str=new char[len+1];
    strcpy(str,s);
    }
    void join(String &a,String &b);
    void display(){
    cout<<str<<endl;
    }
};
void String::join(String &a,String &b){
len=a.len+b.len;
delete str;
str=new char[len+1];
strcpy(str,a.str);
strcat(str,b.str);

}
int main(){
char *first="himanshu";
String name1(first),name2("sristi"),name3("louis"),s1,s2;
s1.join(name1,name2);
s2.join(s1,name3);
name1.display();
name2.display();
name3.display();
s1.display();
s2.display();
}
