#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* link;
};

class list {
public:
    node* head;

    list() {
        head = NULL; // Initialize head to NULL in the constructor
    }

    void create();
    void display();
};

void list::create() {
    node* temp = NULL;
    bool f = true; // Start by allowing node creation

    while (f) {
        temp = new node;
        cin >> temp->data;

        if (temp->data >= 0) {
            temp->link = NULL;

            if (head == NULL) {
                head = temp;
            } else {
                node* t = head;
                while (t->link != NULL) {
                    t = t->link;
                }
                t->link = temp;
            }
        } else {
            f = false; // Stop adding nodes when a negative integer is encountered
            delete temp; // Delete the last node since it's not part of the list
        }
    }
}

void list::display() {
    node* t = head;
    int count = 0;

    cout << "Linked List: ";
    while (t != NULL) {
        if (count > 0) {
            cout << " -> ";
        }
        cout << t->data;
        t = t->link;
        count++;
    }

    if (count == 0) {
        cout << "Linked list is empty.";
    }

    cout << endl;
}

int main() {
    list l1;
    l1.create();
    l1.display();

    return 0;
}
