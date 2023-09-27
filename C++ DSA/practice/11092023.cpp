#include<iostream>
#include<string>
using namespace std;
class data{
public:
	string name;
	int id;int da;
	data(string nam,int i,int d ){
		name=nam;
		id=i;
		da=d;
	}
	data(string nam,int i){
		name=nam;
		id=i;
		da=0;
	}
	void disp(){
		cout<<name<<endl<<id<<endl<<da;
	}
};
int main(){
	data dat("name",2);
	dat.disp();
	return 0;
}