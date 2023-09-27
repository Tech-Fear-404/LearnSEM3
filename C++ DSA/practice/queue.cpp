#include<iostream>
#define maxsize 5
using namespace std;
class queue{
    int q[maxsize];
    int front,rear;
    public:
    queue(){
        front=-1;
        rear=-1;
    }
    void insert(int);
    int Delete();
    bool isFull();
    bool isEmpty();
    int getfront();
};
void queue::insert(int x){
    if(rear==maxsize-1){
        cout<<"Queue is full.\n";
    }
    else{
        rear++;
        q[rear]=x;
    }
}
int queue::Delete(){
    if(front==rear){
    cout<<"Queue is underflow";
    return -1;
    }
    else{
        front++;
        return q[front];
    }
}
bool queue::isFull(){
    if(rear==maxsize-1 && front!=rear){
        return true;
    }
    return false;
}
bool queue::isEmpty(){
    if(rear==-1 || front>=rear){
        return true;
    }
    return false;
}
int queue::getfront(){
    if(front==rear){
    cout<<"Queue is underflow ";
    return -1;
    }
    else{
        return q[front+1];
    }
}
int main(){
 int x;
 queue q1;
 while(cin>>x){
     q1.insert(x);
 }
 for(int i=0;i<2;i++){
     int c=q1.Delete();
     cout<<c<<endl;
 }
cout<< q1.isFull();
cout<<endl<<q1.isEmpty();
cout<<endl<<q1.getfront();
 return 0;
}