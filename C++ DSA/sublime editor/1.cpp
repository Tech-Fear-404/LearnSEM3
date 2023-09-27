#include<iostream>
using namespace std;
int main(){
	int n,c=0;
	cin>>n;
	while(n>0){
		if(n>=100){
			c++;
		n=n-100;
		}
		else if(n>=20){
			c++;
			n=n-20;
		}
		else if(n>=10){
			c++;
			n=n-10;
		}
		else if(n>=5){
			c++;
			n=n-5;
		}
		else{
			c+=n;
			n=0;
			
		}
	}
	cout<<c;
    return 0;
}