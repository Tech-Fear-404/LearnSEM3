#include<iostream>
using namespace std;
int main(){
int a;
int *ptr=&a;
int &b=a;
b=20;
cout<<a<<endl<<b<<endl<<&ptr;
	return 0;
}