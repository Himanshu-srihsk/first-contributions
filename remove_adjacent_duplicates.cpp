#include <bits/stdc++.h>
using namespace std;
char s[51];


string fn(string s){
    if(s.empty())
        return "";

    stack<char>c;
    for(int i=0;i<s.length();i++){
        c.push(s[i]);
    }
    char ch=c.top();
    c.pop();
    string st="";
    int key=0,flag=0;
    while(!c.empty()){
         if(c.top()==ch){
        flag=1;
        key=1;
         }
         else if(c.top()!=ch){
            if(flag==0){
             st+=ch;
            }
             ch=c.top();
           flag=0;
         }


         c.pop();

    }
    if(flag==0){
       st+=ch;
    }
    reverse(st.begin(),st.end());
    if(key){
        st=fn(st);
    }

        return st;


}
int main() {
int t;
cin>>t;
while(t--){

    cin>>s;
    int n=strlen(s);
    string s1=fn(s);
    cout<<s1<<endl;
}
	return 0;
}
