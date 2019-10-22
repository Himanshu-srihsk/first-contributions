#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string str;
	    cin>>str;
	    int n=str.length();
	    int i=0;
	    stack<char>s;
	    int flag=0;
	    while(str[i]!='\0'){
	        char ch=str[i];
	        switch(ch){
	            case '{':
	            case '[':
	            case '(':
	            s.push(ch);
	            break;
	            case '}':
	            case ']':
	            case ')':
	            if(!s.empty()){
	                char c=s.top();
	                s.pop();
	                if((ch=='}' && c!='{') || (ch==']' && c!='[') || (ch==')' && c!='(') ){
	                    //cout<<"not balanced"<<endl;
	                   // break;
	                   flag=1;
	                }
	            }
	            else{
	                //cout<<"not balanced"<<endl;
	                flag=1;
	            }
	            break;

	           default:
	                break;
	        }
	        if(flag==1){
                break;
	        }
	        i++;
	    }
	    if(!s.empty()){
	                flag=1;
	    }
	    if(flag==0){
	        cout<<"balanced"<<endl;
	    }
	    else{
	        cout<<"not balanced"<<endl;
	    }

	}
	return 0;
}
