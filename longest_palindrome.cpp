#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	string s;
	while(t--){
	    cin>>s;
	    int n=s.length();
	    int li=0;
	    int ri=0;
	    int l,r;
	    int currsize=0,maxi=0;
	 for(int i=0;i<n;i++){
	     l=i;
	      r=i;
	       while(l>=0 && r<=n-1  && s[l]==s[r]){

	            currsize=r-l+1;
	            if(currsize>maxi){
	                maxi=currsize;
	                li=l;
	                ri=r;
	            }

	        l--;
	            r++;
	    }

	    l=i;
	    r=i+1;

	     while(l>=0 && r<=n-1  && s[l]==s[r]){
	            currsize=r-l+1;
	            if(currsize>maxi){
	                maxi=currsize;
	                li=l;
	                ri=r;
	            }


	        l--;
	            r++;
	    }

	 }
	 cout<<maxi<<endl;
	 for(int i=li;i<=ri;i++){
	     cout<<s[i];
	 }
	 cout<<endl;


	}
	return 0;
}
