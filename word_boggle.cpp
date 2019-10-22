#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MAX 7
int visited[MAX][MAX];
void wordboggle(char dict[MAX][MAX],vector<string>arr,int r,int c,int m,int n,
int k,string str,vector<string>&res){
    if(r<0 || r>=m || c<0 || c>=n || visited[r][c]==1){
        return;
    }
    if(find(arr.begin(),arr.end(),str)!=arr.end()){
        res.push_back(str);
        str.erase(str.length() - 1);
    }
    visited[r][c]=1;
    wordboggle(dict,arr,r-1,c,m,n,k,str+dict[r][c],res);
    wordboggle(dict,arr,r+1,c,m,n,k,str+dict[r][c],res);
    wordboggle(dict,arr,r,c-1,m,n,k,str+dict[r][c],res);
    wordboggle(dict,arr,r,c+1,m,n,k,str+dict[r][c],res);
    wordboggle(dict,arr,r-1,c+1,m,n,k,str+dict[r][c],res);
    wordboggle(dict,arr,r+1,c+1,m,n,k,str+dict[r][c],res);
    wordboggle(dict,arr,r+1,c-1,m,n,k,str+dict[r][c],res);
    wordboggle(dict,arr,r-1,c-1,m,n,k,str+dict[r][c],res);
     visited[r][c]=0;
    return;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    //string arr[k];
	    string a;
	    vector<string>arr;
	    for(int i=0;i<k;i++){
	        cin>>a;
	        arr.push_back(a);
	    }
	    int m,n;
	    cin>>m>>n;
	    char dict[MAX][MAX];
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++){
	            cin>>dict[i][j];
	        }
	    }
	    vector<string>res;
	    res.clear();
	    string st="";
	    memset(visited,0,sizeof(visited));
	   wordboggle(dict,arr,0,0,m,n,k,st,res);
	   if(res.size()==0){
	        cout<<"-1";
	    }
	    else{
	   for(int i=0;i<res.size();i++){
	       cout<<res[i]<<" ";
	   }
	    }
	   cout<<endl;
	}
	return 0;
}
