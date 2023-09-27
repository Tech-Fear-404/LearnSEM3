#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node* next;

  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
};

class LinkedList {
public:
  Node* head;

  LinkedList() {
    head = NULL;
  }

  void create(int data) {
    head = new Node(data);
  }

  void arrange() {
    Node* cur = head;
    Node* prev = NULL;
    while (cur) {
      if (cur->data % 2 == 1) {
        if (prev == NULL) {
          Node* next = cur->next;
          head = next;
        } else {
          Node* next = cur->next;
          prev->next = next;
        }
        cur->next = head;
        head = cur;
      }
      prev = cur;
      cur = cur->next;
    }
  }

  void display() {
    Node* cur = head;
    while (cur) {
      cout << cur->data << " ";
      cur = cur->next;
    }
    cout << endl;
  }
};

int main() {
  LinkedList llist;
  llist.create(1);
  llist.create(2);
  llist.create(3);
  llist.create(4);
  llist.arrange();
  llist.display();
  return 0;
}
