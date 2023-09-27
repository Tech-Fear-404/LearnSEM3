// You are using GCC
#include<iostream>
#define MAXSIZE 50
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
using namespace std;
class Stack
{
int s[MAXSIZE];
int top;
int n=0;
public:
Stack()
{
top=-1;
}
void push(int);
int pop();
bool isFull(); // true when full otherwise false
bool isEmpty(); // true when empty otherwise false
char getTop(); // return top most element from stack
int ISP(char);
int ICP(char);
void infix_to_postfix(char in[50]);
void calculate(char *str);
};
void Stack::calculate(char *str){
    int n1;
    int n2,n3=0;
    Stack s;
    while(*str){
        if(*str==' ' || *str=='\t'){
            str++;
            continue;
        }
        if(isdigit(*str)){
        n=*str-'0';
        s.push(n);
        }
        else{
           n2=s.pop();
           n1=s.pop();
           switch(*str){
                case '+':
                    n3=n1+n2;
                    break;
                case '-':
                    n3=n1-n2;
                    break;
                case '*':
                    n3=n1*n;
                    break;
                case '/':
                    n3=n1/n2;
                    break;
                case '^':
                    n3=pow(n1,n2);
                    break;
                default:
                    cout<<"Invalid Operator";
                    exit(1);//1 return from sub block , 0 means exit from main block
           }
           s.push(n3);
        }
        *str++;
    }
    cout<<s.pop()<<endl;
}
void Stack::infix_to_postfix(char infix[50]){
    Stack s;
    int i=0;
    char ch,x;
    s.push('#');
    while(infix[i]!='\0'){
        ch=infix[i];
        i++;
        if(ch>='a' && ch<='z'){
            cout<<ch;
        }
        else if(ch==')'){
            while(s.getTop()!='('){
                x=s.pop();
                 cout<<x;
            }
            s.pop();
            }
        else{
            while(ISP(s.getTop())>=ICP(ch)){
                x=s.pop();
                cout<<x;
            }
            s.push(ch);
        }
    }
    while(!s.isEmpty()){
        x=s.pop();
        if(x!='#'){
            cout<<x;
        }
    }
    cout<<endl;
}
int Stack::ISP(char ch){
    switch(ch){
        case '(':
            return 0;
        case '+':
            return 1;
        case '-':
            return 1;
        case '/':
            return 2;
        case '*':
            return 2;
        case '^':
            return 4;
        case '#':
            return -1;
    }
}
int Stack::ICP(char ch){
    switch(ch){
        case '(':
            return 4;
        case '+':
            return 1;
        case '-':
            return 1;
        case '/':
            return 2;
        case '*':
            return 2;
        case '^':
            return 3;
    }
}

char Stack::getTop()
{
char t ='\0';
if(top==-1)
cout<<"Stack is underflow...!"<<endl;
else
t=s[top];
return t;
}
bool Stack::isFull()
{
if(top==MAXSIZE-1)
return true;
else
return false;
}
bool Stack::isEmpty()
{
if(top==-1)
return true;
else
return false;
}
void Stack::push(int x)
{
if(top==MAXSIZE-1)
cout<<"Stack is overflow..!"<<endl;
else
{
top++;
s[top]=x;
}
}
int Stack::pop()
{
int t=-1;
if(top==-1)
cout<<"Stack is underflow...!"<<endl;
else
{
t=s[top];
top--;
}
return t;
}
int main()
{
Stack s;
char in[50];
cin.getline(in,MAXSIZE);
s.calculate(in);
// s.infix_to_postfix(in);

return 0;
}