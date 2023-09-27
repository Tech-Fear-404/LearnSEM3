//linklist sort;
#include<iostream>
using namespace std;
class node{
public:
	int data;
	node *link;
};
class list{
public:
	node *head,*newhe;
	list(){
		head=NULL;
		newhe=NULL;
	}
	void create();
	void sort();
	void disp();
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
		cout<<t->data<<" ";
		t=t->link;
	}
}
void list::sort() {
    if (head == NULL || head->link == NULL) {
        return;
    }
    node* sorted = NULL;
    node* current = head; 
    while (current != NULL) {
        node* next = current->link; 
        if (sorted == NULL || sorted->data >= current->data) {
            current->link = sorted;
            sorted = current;
        } 
		else {
            node* search = sorted;
            while (search->link != NULL && search->link->data < current->data) {
                search = search->link;
            }
            current->link = search->link;
            search->link = current;
        }
        current = next;
    }
    head = sorted; 
}
int main(){
	list* l[2];
	l[0]==new list();
	l[1]==new list();
	int n;
	cin>>n;
	while(n>0){
		l[0]->create();
		n--;
	}
	int m;
	cin>>m;
	while(m>0){
		l[1]->create();
		m--;
	}
	l[0]->disp();
	cout<<endl;
	l[0]->sort();
	l[0]->disp();
	l[1]->disp();
	cout<<endl;
	l[1]->sort();
	l[1]->disp();
	return 0;
}
