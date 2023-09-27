#include<iostream>
using namespace std;
class rectangle{
	// int len,bred,value;
  int id;
public:
	// // rectangle(int a,int b):len(a),bred(b){}
	// // int area(){
	// // 	cout<<"Area is ";
	// // 	cout<<len*bred;
	// // }
  // rectangle(int value):value(value){
  //   cout<<"value is "<<value<<endl;
  // }
  rectangle(int a):id(a){}
  ~rectangle(){
    cout<<"destructor with id :"<<id; 
  }
};
int main(){
rectangle r1(5);
cout<<endl;
rectangle r2(6);
rectangle r3(7);
//r1.area();
}
