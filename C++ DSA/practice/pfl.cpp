#include<iostream>
#include<fstream>
using namespace std;
int main(){

//    string hello;
//	ofstream of("result.txt");
//    getline(cin,hello);
//    of<<hello;
//    of.close();
//    cout<<"Data saved. "<<endl;
//    ifstream ip("result.txt");
//    getline(ip,data);
//    cout<<data<<endl;
//    ip.close();
//ifstream i("Student.txt");
//	string data;
//	int fee;
//	cin>>data>>fee;
//	ofstream of("Student.txt");
//	of<<data<<"\t"<<fee;
//	of.close();
//string dat;
//int fe;
//i>>dat>>fe;
//cout<<dat<<"\t"<<fe;
//i.close();
ofstream fout;
fout.open("result.txt");
fout<<"India\n"<<"USA\n"<<"UK\n";
fout.close();
fout.open("result1.txt");
fout<<"Delhi\n"<<"Washington\n"<<"London\n";
fout.close();
ifstream fin,fiin;
fin.open("result.txt");
fiin.open("result1.txt");
string co;
while(getline(fin,co)){
	cout<<co<<endl;
}
fin.close();
fin.open("result1.txt");
string co1;
while(getline(fin,co1)){
	cout<<co1<<endl;
}
fin.close();
	return 0;
}
