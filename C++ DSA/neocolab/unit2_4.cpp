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
	int n=0;
	void create();
	void display();
};
void list::create(){
	bool f=true;
	int check;
	while(f){
		node *temp=new node;
		cin>>temp->data;
		cout<<"Node inserted\n";
		temp->link=head;
		head=temp;
		n++;
		cin>>check;
		if(check==1){
			f=false;
		}
	}
}
void list::display(){
	node *t=head;
	cout<<"Linked List: ";
	while(t!=NULL){
		cout<<t->data<<" ";
		t=t->link;
	}
	cout<<"\nNode ended";
}
int main(){
	list l1;
	l1.create();
	l1.display();
}
