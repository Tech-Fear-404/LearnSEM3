#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int ar[n];
	for(int i=0;i<n;i++){
		cin>>ar[i];
	}
	int q;
	cin>>q;
	int ar1[3][3];
	for(int i=0;i<q;i++){
		for(int j=0;j<3;j++){
			cin>>ar1[i][j];
		}
	}
	int ar3[n];
	int co=0;
	while(co<n){
		ar3[co]=ar[co];
		co++;
	}
	int pos;
	for(int i=0;i<q;i++){
		if(ar1[i][0]==1){
			int j=0;
			while(j<n){
				ar3[j]=ar[n-j-1];
				j++;
			}
		}
		if(ar1[i][0]==2){
			int temp=ar3[(ar1[i][1])-1];
			ar3[(ar1[i][1])-1]=ar3[(ar1[i][2])-1];
			ar3[(ar1[i][2])-1]=temp;
		}
		if(ar1[i][0]==3){
			for(int j=0;j<n;j++){
				if(ar3[j]==(ar1[i][1])-1){
						pos=j+1;
						break;
				}
			}
			cout<<pos;
		}
	}
	return 0;
}