#include<iostream>
using namespace std;
class node{
public:
	int data;
	node *link;
};
class list{
public:
	node *head;
	list(){
		head=NULL;
	}
	void create();
	void display();
	void update();
};
void list::create(){
	node *temp= new node;
	cin>>temp->data;
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
void list::display(){
	node *t=head;
	while(t!=NULL){
		cout<<t->data<<" ";
		t=t->link;
	}
	cout<<endl;
}
void list::update(){
	node *temp=new node;
	cin>>temp->data;
	node *t=head,*prev;
	while(t->link!=NULL && t->data<temp->data){
		prev=t;
		t=t->link;
	}
	prev->link=temp;
	temp->link=t;
}
int main(){
	list l1;
	int n;
	cin>>n;
	while(n>0){
		l1.create();
		n--;
	}
	//l1.display();
	l1.update();
	l1.display();
	return 0;
}