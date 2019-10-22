#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 string out[1000];
int findsol(string s,string s1,int n,string out[1000]){
    if(n==0){
        out[0]=s1;
        return 0;
    }
    if(n==1){
        out[0]=s;
        return 1;
    }
  int f=findsol(s.substr(1),s1,n-1,out);
  string temp[1000];
  for(int i=0;i<f;i++){
      temp[i]=out[i];
  }
  for(int i=0;i<f;i++){
      out[i]=s[0]+s1+temp[i];
  }
  for(int i=0;i<f;i++){
      out[i+f]=s[0]+temp[i];
  }

  return 2*f;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    string s1=" ";
	    int n=s.length();


	    int ans=findsol(s,s1,n,out);
	    for(int i=0;i<ans;i++){
	        cout<<"("<<out[i]<<")";
	    }

	    cout<<endl;
	}
	return 0;
}
