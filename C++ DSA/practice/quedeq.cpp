#include<iostream>
using namespace std;
class node{
public:
	int data;
	node *next=NULL;
};
class queue{
public:
	node *front,*rear;
	queue(){
		front=rear=NULL;
	}
	void enque(int x){
		node *temp=new node;
		temp->data=x;
		if(front==NULL && rear==NULL){
			front=rear=temp;
			return;
		}
		rear->next=temp;
		rear=temp;
	}
	void deque(){
		if(front==NULL){
			return;
		}
		node *temp=front;
		cout<<temp->data<<endl;
		front=front->next;
		delete(temp);
	
	}
	bool isempty(){
		if(front==NULL){
			return true;
		}
		return false;
	}
};
int main(){
	queue q1;
	int n;
	int con=-1;
	while(true){
		cin>>n;
		if(n==-1){
			break;
		}
		q1.enque(n);
	}
	while(!(q1.isempty())){
		q1.deque();
	}
	
	return 0;
}
