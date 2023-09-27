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
	int n;
	void create();
	void arrange();
	void display();
};
void list::create(){
	cin>>n;
	int count=0;
	while(count<n){
		node *temp=new node;
		cin>>temp->data;
		temp->link=head;
		head=temp;
		count++;
	}
}
void list::arrange(){
	node *t=head,*pre,*cur;
	while(t!=NULL){
		if((t->data)%2!=0){
			pre=t;
			cur=t;
			while(cur->link!=NULL && (cur->data)%2!=0){
				cur=cur->link;
			}
			int temp=cur->data;
			cur->data=pre->data;
			pre->data=temp;
		}
		t=t->link;
	}
}
void list::display(){
	node *t=head;
	while(t!=NULL){
		cout<<t->data<<" ";
		t=t->link;
	}
}
int main(){
	list l1;
	l1.create();
	l1.arrange();
	l1.display();
	return 0;
}