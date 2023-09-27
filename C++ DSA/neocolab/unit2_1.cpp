#include<iostream>
using namespace std;

class node {
public:
    string data;
    node* link;
};

class list {
public:
    node* head;
    int n;

    list() {
        head = NULL;
    }

    void create();
    void insertpos();
    void display();
};

void list::create() {
    node* temp;
    node* t; // New node
    for (int i = 0; i < n; i++) {
        t = new node; // Allocate memory for t
        cin >> t->data;
        t->link = NULL;
        if (head == NULL) {
            head = t;
        } else {
            temp->link = t;
        }
        temp = t;
    }
}

void list::insertpos() {
    node* temp = new node;
    int pos;
    cin >> temp->data >> pos;
    if (pos <= 0) {
        cout << "Invalid position." << endl;
        delete temp; // Release memory for temp
        return;
    }
    node* cur = head, * pre = NULL;
    int count = 1;
    while (count < pos && cur != NULL) {
        pre = cur;
        cur = cur->link;
        count++;
    }
    if (pre == NULL) {
        temp->link = head;
        head = temp;
    } else if (cur == NULL) {
        temp->link = NULL;
        pre->link = temp;
    } else {
        pre->link = temp;
        temp->link = cur;
    }
}

void list::display() {
    node* t = head;
    while (t != NULL) {
        if (t->link != NULL) {
            cout << t->data << " ==> ";
        } else {
            cout << t->data;
        }
        t = t->link;
    }
    cout << endl;
}

int main() {
    list l1;
    cin >> l1.n;
    l1.create();
    l1.display();
    l1.insertpos();
    l1.display();
    return 0;
}

