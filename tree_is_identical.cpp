#include <bits/stdc++.h>
using namespace std;
struct node{
int data;
struct node *left,*right;
node(int x){
        data = x;
        left = right = NULL;
    }
};
/*struct node* newnode(int d){
node *temp=(struct node *) malloc( sizeof(struct node) );
//node *temp[sizeof(struct node)];
temp->data=d;
temp->left=temp->right=NULL;
return temp;
}*/
bool isidentical(node *root,node *root1){
  //  cout<<root->data <<" "<<root1->data<<endl;
if(root == NULL && root1==NULL){
    return true;
}
if(root==NULL || root1 ==NULL){
    return false;
}
if(root->data !=root1->data){
        return false;
    }
if(root->data ==root1->data){
    bool left=isidentical(root->left,root1->left);
     bool right=isidentical(root->right,root1->right);
     return(left && right);
}

        return false;
}
int main(){
int t;
cin>>t;

while(t--){
    int n;
    cin>>n;
    //root1
    map<int,node *>m;
struct node *root=NULL;
    int a,b;
    char c;
    struct node *parent;
         struct node *child;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;

        if(m.find(a) ==m.end()){
               parent=new node(a);
            m[a]=parent;
            if(root==NULL){
                root=parent;
            }
        }
        else{
            parent=m[a];
        }
      child=new node(b);
        if(c=='L'){
            parent->left=child;
        }
        else{
            parent->right=child;
        }
        m[b]=child;


    }
    //root 2
    cin>>n;
    map<int,node *>mm;
    struct node *root1=NULL;


    for(int i=0;i<n;i++){
        cin>>a>>b>>c;

        if(mm.find(a) ==mm.end()){
              parent=new node(a);
            mm[a]=parent;
            if(root1==NULL){
                root1=parent;
            }
        }
        else{
           parent=mm[a];
        }
      child=new node(b);
        if(c=='L'){
            parent->left=child;
        }
        else{
            parent->right=child;
        }
        mm[b]=child;


    }

    cout<<isidentical(root,root1)<<endl;
}
}
