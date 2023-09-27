#include<iostream>
#include<string>
using namespace std;
int main(){
	string s1("man");
	string s2("h1");
	string s3;
	s3=s1;
	cout<<s3<<endl;
	s3="neither "+s1+" nor ";
	s3+=s2;
	cout<<s3<<"\n";
	s1.swap(s2);
	cout<<s2<<"\n";
	return 0; 
}
