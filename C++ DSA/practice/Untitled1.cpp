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
		void disp();
		void insertbeg();
		void insertlas();
		void insertpos();
};
void list::create(){
	node *temp=new node;
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
void list::disp(){
	node *t=head;
	while(t!=NULL){
		if(t->link!=NULL)
		cout<<t->data<<" ==> ";
		else{
			cout<<t->data;
		}
		t=t->link;
	}
}
void list::insertbeg(){
	node *temp=new node;
	cin>>temp->data;
	temp->link=NULL;
	if(head==NULL){
		head=temp;
	}
	else{
		temp->link=head;
		head=temp;
	}
}
void list::insertlas(){
	node *temp=new node;
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
void list::insertpos(){
	node *temp=new node;
	cin>>temp->data;
	temp->link=NULL;
	if(head==NULL){
		head=temp;
	}	
	else{
		int cur=1;
		int pos;
		cout<<" enter the position: ";
		cin>>pos;
		node *t=head,*pre;
		while(cur!=pos && t->link!=NULL){
			pre=t;
			t=t->link;
			cur++;
		}
		if(cur==pos){
			temp->link=pre->link;
			pre->link=temp;
		}
	}
}
int main(){
	list l1;
	int n;
	cin>>n;
	while(n>0){
		l1.create();
		n--;	
	}
	l1.disp();
	l1.insertbeg();
	l1.disp();
	l1.insertpos();
	l1.disp();
	return 0;
}

