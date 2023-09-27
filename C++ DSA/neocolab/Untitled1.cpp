#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node* next;
};

class List {
public:
  Node* head;

  List() {
    head = NULL;
  }

  void create(int n) {
    int data;
    Node* cur = NULL;
    for (int i = 0; i < n; i++) {
      Node* temp = new Node;
      cin >> data;
      temp->data = data;
      temp->next = NULL;

      if (head == NULL) {
        head = temp;
        cur = temp;
      } else {
        cur->next = temp;
        cur = temp;
      }
    }
  }

  void display() {
    Node* temp = head;
    while (temp != NULL) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }

  void sort(int size) {
    Node* temp = head;
    Node* new_head = NULL;
    Node* mini;
    Node* iter;
    Node* prev;

    while (temp->next != NULL) {
      mini = temp;
      iter = temp->next;
      prev = temp;

      while (iter != NULL) {
        if (iter->data < mini->data) {
          mini = iter;
        }
        iter = iter->next;
      }

      if (new_head == NULL) {
        new_head = mini;
      } else {
        prev->next = mini;
      }

      prev = mini;
      temp = temp->next;
    }

    head = new_head;
  }
};

int main() {
  List l[2];
  int size1;
  cin >> size1;
  l[0].create(size1);
  l[0].display();
  cout << endl;
  l[0].sort(size1);
  l[0].display();

  int size2;
  cin >> size2;
  l[1].create(size2);
  l[1].display();

  return 0;
}

