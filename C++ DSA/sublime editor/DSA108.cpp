#include<iostream>
using namespace std;
enum class letteranalyze{
	vowel,consonant,invalid
};
letteranalyze check(char ch){
	ch=tolower(ch);
	switch(ch){
case 'a':
case 'e':
case 'i':
case 'o':
case 'u':
	return letteranalyze::vowel;
default :

	return isalpha(ch) ? letteranalyze::consonant : letteranalyze::invalid;
}
};
int main(){
	char ch;
	cin>>ch;
	letteranalyze res=check(ch);
	switch(res){
	case letteranalyze::vowel:
		cout<<"vowel";
		break;
	case letteranalyze::consonant:
		cout<<"consonant";
		break;
	default:
		cout<<"invalid input";
	}
	return 0;
}
