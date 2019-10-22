/*
 * C++ Program to Implement Longest Prefix Matching
 */
#include <bits/stdc++.h>
using namespace std;
class node{
public:
    char  data;
    node *child[128];
    node(){
     for (int i = 0; i < 128; i++)
            child[i] = NULL;
    }
};
class trie{
private:
    node *root;
public:
    trie(){
      root = new_node(0);
    }
    node* new_node(int data){
    node *Q = new node();
            Q->data = data;
            return Q;
    }
    void add(string s){
    node *cur=root;
    for(int i=0;i<s.length();i++){
           char ch=s[i] - 'A';
    node* ch1=cur->child[ch];
        if (ch1==NULL)
        {
            ch1=new_node(s[i]);
            cur->child[s[i] - 'A'] =ch1;
        }

                cur = ch1;
    }
    }

    void check(node *cur, string S, int i){
    if(cur){
        cout<<cur->data;
        if (i < S.length())
             check(cur->child[S[i]-'A'],S,i+1);
    }
    }

    void checkroot(string S)
        {
            if (root && S.length() > 0 && (S[0]-'A'))
                check(root->child[S[0] - 'A'],S,1);
            else
                cout<<"\nEmpty root \n";
        }
};
int main(){
 trie dict;
    dict.add("are");
    dict.add("area");
    dict.add("base");
    dict.add("cat");
    dict.add("cater");
    dict.add("basement");
    string input;
    input = "caterer";
    cout<<input << ":   ";
    dict.checkroot(input);
    cout<<endl;
    input = "basement";
    cout<<input << ":   ";
    dict.checkroot(input);
    cout<<endl;
    input = "are";
    cout<<input << ":   ";
    dict.checkroot(input);
    cout<<endl;
    input = "arex";
    cout<<input << ":   ";
    dict.checkroot(input);
    cout<<endl;
    input = "basemexz";
    cout<<input << ":   ";
    dict.checkroot(input);
    cout<<endl;
    input = "xyz";
    cout<<input << ":   ";
    dict.checkroot(input);
    cout<<endl;
    return 0;
}
