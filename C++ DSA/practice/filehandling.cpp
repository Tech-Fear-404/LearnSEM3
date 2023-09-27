#include<iostream>
#include<fstream>
using namespace std;
// int main(){
// //	char s[30];
// //	ofstream fileout;
// //	ifstream filein;
// //	fileout.open("data",ios::app);
// //	fileout<<"hello world";
// //	fileout.close();
// //	filein.open("data",ios::in);
// //	filein.getline(s,30);
// //	cout<<s;
// // ofstream fp;
// // fp.open("output.txt",ios::out);
// // if(fp){

// // fp<<"Lovely ptofessional university "<<endl;
// // fp<<"c++ tutorials"<<endl;
// // fp<<"Object oriented programming"<<endl;
// // }
// // else cout<<"Error file Unable to open"<<endl;
// 	// ofstream myFile;
// 	// ifstream file;
// 	// char ch[30];
// 	// char text;
// 	// cout<<"Enter some text here : \n";
// 	// cin.getline(ch,30);
// 	// myFile.open("oputput.txt",ios::out);
// 	// if(myFile){
// 	// 	myfile<<ch;
// 	// 	cout<<"Data saved successfully.\n";
// 	// }
// 	// else cout<<"Unable to open file\n";
// 	// myFile.close();
// 	// file.open("input.txt",ios::in);
// 	// if(file){
// 	// 	file.seekg(7,ios::beg);
// 	// 	cout<<"The output is ";
// 	// 	while(!file.eof()){
// 	// 		file.get(text);
// 	// 		cout<<text;
// 	// 	}
// 	// }
// 	// else cout<<"Error while openenig file\n";
// 	// file.close();
// 	return 0;
// }
// class Employee{
// private:
// 	char name[30];
// 	char employee_id[20];
// 	char joining_Date[30];
// 	char position[20];
// 	char martial_status[30];
// 	char age[30];
// 	char salary[20];
// 	char comment[20];
// public:
// 	void getEmp_data(){
// 		cout<<"Welcome to InfoBrother: "<<endl;
// 		cout<<"=======================";
// 		cout<<"\n\n Employee Name: ";
// 		cin.getline(name,30);
// 		cout<<"Employee ID: ";
// 		cin.getline(employee_id,20);
// 		cout<<"joining Date: ";
// 		cin.getline(joining_Date,30);
// 		cout<<"Position: ";
// 		cin.getline(position,20);
// 		cout<<"martial status: ";
// 		cin.getline(martial_status,30);
// 		cout<<"Age: ";
// 		cin.getline(age,30);
// 		cout<<"salary: ";
// 		cin.getline(salary,20);
// 		cout<<"comment: ";
// 		cin.getline(comment,20);
// 	}
// 	void showemp_data(){
// 		cout<<"Employee Data "<<endl;
// 		cout<<"=======================";
// 		cout<<"\n\nName: "<<name<<endl;
// 		cout<<"Employee ID: "<<employee_id<<endl;
// 		cout<<"joining Date: "<<joining_Date<<endl;
// 		cout<<"Position: "<<position<<endl;
// 		cout<<"martial status: "<<martial_status<<endl;
// 		cout<<"Age: "<<age<<endl;
// 		cout<<"Total salary: "<<salary<<endl;
// 		cout<<"comment: "<<comment<<endl;
// 	}
// };
// class library{
// public:
// 	Employee emp;
// 	fstream fp,fp1;
// 	void writeEmployee(){
// 		fp.open("Employee.txt",ios::out);
// 		if(fp){
// 			emp.getEmp_data();
// 			fp.write((char*)&emp,sizeof(emp));
// 			cout<<"Record tored successfully: "<<endl;
// 		}
// 		fp.close();
// 	}
// 	void W_display(){
// 		fp.open("Employee.txt",ios::in);
// 		if(fp){
// 			while(fp.read((char*)&emp,sizeof(emp))){
// 				emp.showemp_data();
// 			}
// 		}
// 	}
// };
// int main(){
// 	library lib;
// 	lib.writeEmployee();
// 	lib.W_display();
// 	return 0;
// }
//binary file operations