#include <bits/stdc++.h>
using namespace std;
class link{
  public:
int data;
link *next;

link(int d){
data=d;
next=NULL;
}
};
void showlinklist(link **head_ref){
link *tail=*head_ref;
while(tail!=NULL){
    cout<<tail->data<<" ";
    tail=tail->next;
    }
}
void appendlink(link **head_ref,link **tail_ref,int d){
link *newnode=new link(d);
if(*head_ref==NULL){
    *head_ref=newnode;
}
else{
    (*tail_ref)->next=newnode;
}
*tail_ref=newnode;
}

link* merge_rev(link *head1,link *head2){
link *head3=NULL;
if (head1==NULL && head2==NULL) return NULL;
while(head1!=NULL && head2!=NULL){
        if(head1->data <= head2->data){

                    link *tail=head1->next;
                       head1->next=head3;
                       head3=head1;


               head1=tail;
        }
        else{

                     link *tail=head2->next;
                       head2->next=head3;
                       head3=head2;


               head2=tail;
        }
}
while(head1!=NULL){


                   link *tail=head1->next;
                       head1->next=head3;
                       head3=head1;

               head1=tail;
}

while(head2!=NULL){

                      link *tail=head2->next;
                       head2->next=head3;
                       head3=head2;
               head2=tail;
}
return head3;
}



link* merge1(link *head1,link *head2){
link *head3=NULL;
link *tail=NULL;
if(head1==NULL){
    return head2;
}
if(head2==NULL){
    return head1;
}

if(head1 && head2){
    if(head1->data <=head2->data){
        tail=head1;
        head1=head1->next;
    }else{
    tail=head2;
    head2=head2->next;
    }
}
head3=tail;
while(head1!=NULL && head2!=NULL){
        if((head1)->data < (head2)->data){

                    tail->next=head1;
                 tail=head1;
               head1=head1->next;
        }
        else{

                   tail->next=head2;
                 tail=head2;
               head2=head2->next;
        }
}
while(head1!=NULL){

    tail->next=head1;
                 tail=head1;
               head1=head1->next;
}

while(head2!=NULL){
     tail->next=head2;
                 tail=head2;
               head2=head2->next;
}
return head3;
}
link* reverse1(link *head){
link *temp=NULL;
link *prev=NULL;
while(head!=NULL){
        temp=head->next;
     head->next=prev;
     prev=head;
    head=temp;

}
return prev;
}
void sortlink(link **head_ref,link* curr){
if(*head_ref==NULL || (*head_ref)->data>=curr->data){
    curr->next=*head_ref;
    *head_ref=curr;
}
else{
    link *present=*head_ref;
    while(present->next !=NULL && present->next->data < curr->data){
        present=present->next;
    }
    curr->next=present->next;
    present->next=curr;
}
}
void insertionsort(link **head_ref){
link *sorted=NULL;
link *curr=*head_ref;
while(curr!=NULL){
        link *temp=curr->next;
    sortlink(&sorted,curr);
    curr=temp;
}
*head_ref=sorted;
}


int main(){
    int n,m,n1,m1;
cout<<"enter size of lnklist1:";
cin>>n;
link *head=NULL,*tail=NULL;
    int k;
for(int i=0;i<n;i++){
    cin>>k;
    //link *newnode=new link(k);
    appendlink(&head,&tail,k);
}

cout<<"enter size of lnklist2:";
cin>>n1;
link *head1=NULL,*tail1=NULL;
    int k1;
for(int i=0;i<n1;i++){
    cin>>k1;
    //link *newnode=new link(k);
    appendlink(&head1,&tail1,k1);
}
showlinklist(&head);
cout<<"\n";
showlinklist(&head1);
cout<<"added list="<<endl;

cout<<"reverse list using merge - rev show="<<endl;
link *newhead1=merge_rev(head,head1);
showlinklist(&newhead1);

/*
link *newhead=merge1(head,head1);
cout<<"added list show="<<endl;
showlinklist(&newhead);
cout<<"reverse list show="<<endl;
newhead1=reverse1(newhead);
showlinklist(&newhead1);
*/

//sort link list
link *head4=NULL;
cout<<"enter size of lnklist4:";
cin>>n;

for(int i=0;i<n;i++){
    cin>>k1;
    //link *newnode=new link(k);
    appendlink(&head4,&tail1,k1);
}
showlinklist(&head4);
insertionsort(&head4);
cout<<"sorted linklist"<<endl;
showlinklist(&head4);
cout<<"reverse list show="<<endl;
newhead1=reverse1(head4);
showlinklist(&newhead1);

}
