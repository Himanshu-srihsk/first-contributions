#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct TrieNode{
map<char,TrieNode*>children;
bool endofword;
TrieNode(){
endofword=false;
}
};

void insert(TrieNode *root,string word){
TrieNode *current=root;
for(int i=0;i<word.size();i++)
{
    char ch=word[i];
    TrieNode  *node=current->children[ch];
if(node==NULL){
node=new TrieNode();
current->children[word[i]]=node;
}
current=node;
}
current->endofword=true;
}

bool prefixsearch(TrieNode *root,string word){
TrieNode *current=root;
for(int i=0;i<word.size();i++)
{char ch=word[i];
    TrieNode  *node=current->children[ch];
if(!node)
return false;
current=node;
}
return (current->endofword);
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	   TrieNode *root=new TrieNode();
	   string s[n];
    for(int i=0;i<n;i++)
           {cin>>s[i];
           insert(root,s[i]);}

     string p;
         cin>>p;
          cout<<prefixsearch(root,p)<<endl;

	}
	return 0;
}
