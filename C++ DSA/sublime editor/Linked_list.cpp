#include<iostream>
using namespace std;
class node{
public:
int data;
node *link;  
};
class linkedlist{
public:
node *head;
linkedlist(){
head=NULL;
}
void create();
void display();
void insertlast();
void insertfirst();
void insertpos();
void deletebegin();
void deletelast();
void deletepos();
};
void linkedlist::create(){
int n;
node *temp=new node;
cout<<"Enter the data insert into node: ";
cin>>n;
temp->data=n;
temp->link=NULL;
if(head==NULL){
head=temp;
}
else{
node *t=head;
while(t->link!=NULL){
t=t->link;
}
t->link=temp;
}
}
void linkedlist::display(){
node *t=head;
while(t!=NULL){
if(t->link!=NULL){
cout<<t->data<<" ==> ";
}
else{
cout<<t->data;
}
t=t->link;
}
}
void linkedlist::insertlast(){
int n;
node *temp=new node;
cout<<"Enter the data insert into node: ";
cin>>n;
temp->data=n;
temp->link=NULL;
if(head==NULL){
head=temp;
}
else{
node *t=head;
while(t->link!=NULL){
t=t->link;
}
t->link=temp;
}
}
void linkedlist::insertfirst()
{
node *t=new node;
cin>>t->data;
t->link=head;
head=t;
}
void linkedlist::insertpos(){
node *temp=new node;
int pos;
cout<<"Enter the position at which you want to add a node: ";
cin>>pos;
cout<<"Enter the data: ";
cin>>temp->data;
node *cur=head,*pre=NULL;
int count=1;
while( count<pos && cur->link!=NULL){
pre=cur;
cur=cur->link;
count++;
}
if(count==pos){
pre->link=temp;
temp->link=cur;
}
else{
cout<<"Cannot insert data . End reached.\n";
}
}
void linkedlist::deletebegin(){
node *temp=head;
if(head==NULL){
cout<<"DELETE NOT POSSIBLE.\n";
}
else{
head=head->link;
cout<<"Deleted Data is : "<<temp->data<<endl;
delete temp;
}
}
void linkedlist::deletelast(){
node *temp=head,*pre=NULL;
while(temp->link!=NULL){
pre=temp;
temp=temp->link;
}
pre->link=NULL;
delete temp;
}
void linkedlist::deletepos(){
node *temp=head,*pre=NULL;
int pos;
cout<<"Enter the position which you want to delete: ";
cin>>pos;
int count=1;
while(pos!=count && temp->link!=NULL){
pre=temp;
temp=temp->link;
count++;
}
if(count==pos){
pre->link=temp->link;
delete temp;
}
else{
cout<<"Deletion not possible.\n";
}
}
int main(){
linkedlist l1;
int n;
cout<<"Enter the number of elements you want to enter: ";
cin>>n;
for(int i=0;i<n;i++){
l1.create();
}
cout<<"Your created list is : ";
l1.display();
cout<<endl;
// l1.insertlast();
// l1.display();
// l1.insertfirst();
// l1.insertpos();
// l1.deletebegin();
// l1.display();
// l1.deletelast();
l1.deletepos();
l1.display();
return 0;
}
