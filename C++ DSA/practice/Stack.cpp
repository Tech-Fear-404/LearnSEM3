#include <iostream>
#define max_size 5
using namespace std;

class Stack {
private:
  int top;
  int s[max_size];
public:
  Stack() {
    top = -1;
  }

  bool is_full() {
    return top == max_size - 1;
  }

  bool is_empty() {
    return top == -1;
  }

  void push(int x) {
    if (is_full()) {
      cout << "Stack Overflow\n";
      return;
    }
    top++;
    s[top] = x;
  }

  int pop() {
    if (is_empty()) {
      cout << "Stack Underflow.\n";
      return -1;
    }
    int t = s[top];
    top--;
    return t;
  }
  int gettop(){
  	if (is_empty()) {
      cout << "Stack Underflow.\n";
      return -1;
    }
    return s[top];
  }
};

int main() {
  Stack s;

  cout << s.is_empty() << endl << s.is_full() << endl;

  for (int i = 0; i < 5; i++) {
  	int t;
  	cin>>t;
    s.push(t);
  }
  cout<<endl<<s.gettop();
  return 0;
}
