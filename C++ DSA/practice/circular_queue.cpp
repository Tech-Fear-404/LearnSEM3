#include<iostream>
#define maxsize 5
using namespace std;
class cqueue{
    int q[maxsize];
    int front,rear;
    public:
    cqueue(){
        front=-1;
        rear=-1;
    }
    void insert(int);
    int Delete();
};
void cqueue::insert(int x){
    if((rear==maxsize-1 && front==0) || rear==front-1){
        cout<<"Circular Queue is full.\n";
    }
    else if(front==-1 && rear==-1){ //first element
        front=rear=0;
        q[rear]=x;
    }
    else if(front!=0 && rear==maxsize-1){
        rear=0;
        q[rear]=x;
    }
    else{
        rear++;
        q[rear]=x;
    }
}
int cqueue::Delete(){
    int t;
    if( front==-1){
    cout<<"Circular Queue is Empty.";
    return -1;
    }
    else if(front==rear){ //when insert element same as no. of elements to be deleted
        t=q[front];
        front=rear=-1;
        return t;
    }
    else if(front==maxsize-1){
        t=q[front];
        front=0;
        return t;
    } 
    else{
        t= q[front];
        front++;
        return t;
    }
}
bool cqueue::isFull(){
    if(rear==maxsize-1 && front!=rear){
        return true;
    }
    return false;
}
int main(){
 cqueue q1;
 int x;
 while(cin>>x){
     q1.insert(x);
 }
 for(int i=0;i<2;i++){
     int c=q1.Delete();
     cout<<c<<endl;
 }
q1.insert(33);
q1.insert(33);
 return 0;
}