//print leftview of a binary tree

//left view of binary tree

#include <bits/stdc++.h>
using namespace std;
class node{
    public:
int data;
node *left,*right;
node(int d){
data=d;
left=right=NULL;
}
};
int height_tree(node *root){
if(root==NULL){
    return 0;
}
int l=height_tree(root->left);
int r=height_tree(root->right);
return max(l,r)+1;
}
void leftViewutil(node* root,bool *visited,int h,int x){
    if(root==NULL){
        return;
    }
    if(visited[x]==false){
        cout<<root->data<<" ";
        visited[x]=true;
    }
if(h-1==x){
    return;
}
if(root->left)
  leftViewutil(root->left,visited,h,x+1);
leftViewutil(root->right,visited,h,x+1);

}
void leftView(node *root)
{
   // Your code here
   int height=height_tree(root);
   bool *visited=new bool[height];
   for(int i=0;i<height;i++){
    visited[i]=false;
   }
   leftViewutil(root,visited,height,0);
cout<<endl;
}

int main(){
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    map<int,node*>m;
    node *root=NULL;
    while(n--){
        int a,b;
        char c;
        cin>>a>>b>>c;
        node *parent=new node(a);
        if(m.find(a)==m.end()){
                 m[a]=parent;
            if(root==NULL){
                root=parent;
            }
        }else{
            parent=m[a];
        }
        node *child=new node(b);
            if(c=='L'){
                parent->left=child;
            }else{
             parent->right=child;
            }
        m[b]=child;
    }
    leftView(root);
}
}
