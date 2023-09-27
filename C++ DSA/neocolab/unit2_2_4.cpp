#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* link;
};
class list{
    public:
        int n;
        node *head,*new_head;
        list(){
            head=NULL;
            new_head=NULL;
        }
        void create(int);
        void display();
        void sort(int);
};
void list::create(int n){
    node *cur;
    int count=0;
    while(count<n){
        node *temp=new node;
        temp->link=NULL;
        cin>>temp->data;
        if(head==NULL){
        head=temp;  
        }
        else{
        cur->link=temp; 
        }
        cur=temp;
        count++;
    }
}
void list::display(){
   node *t=head;
   while(t!=NULL){
       cout<<t->data<<" ";
       t=t->link;
   }
}
// void list::sort(int size){
//     node *temp=head,*new_head=NULL,*mini,*iter,*prev;
//     while(temp->link!=NULL){
//         int min=temp->data;
//         iter=temp->link;
//         while(iter!=NULL){
//             if(iter->data<min){
//                 mini=iter;
//             }
//         iter=iter->link;
//         }
//         if(new_head==NULL){
//         new_head=mini;
//         prev=new_head;  
//         }
//         else{
//             prev->link=mini;
//             prev=prev->link;
//         }
//         temp=temp->link;
//     }
//     cout<<new_head->data;
// }
void sort(){
    node *t=head,*iter=NULL,*up;
    while(t->link!=NULL){
        int min=t->data;
        iter=t->link;
        while(iter!=NULL){
            if((iter->data)<min){
                up=iter;
                min=iter->data;
            }
            if(new_head==NULL){
                up->data=min;
                
            }
            else{
                node *temp=new_head;
                while(temp->link!=NULL){
                    temp=temp->link;
                }

            }
            iter=iter->link;
        }
    }
}
int main(){
   list l[2];
   int size1;
   cin>>size1;
   l[0].create(size1);
   l[0].display();
   l[0].sort(size1);
   cout<<endl;
   // l[0].sort(size1);
   // int size2;
   // cin>>size2;
   // l[1].create(size2);
return 0;
}
