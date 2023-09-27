#include <iostream>

using namespace std;

// Define the structure for a node in the linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

// Function to insert a node at the end of a linked list
void insertEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to merge two linked lists into a sorted, distinct union linked list
Node* mergeLinkedLists(Node* list1, Node* list2) {
    Node* mergedHead = NULL;
    Node* mergedTail = NULL;

    while (list1 || list2) {
        int minValue;

        if (list1 && (!list2 || list1->data <= list2->data)) {
            minValue = list1->data;
            list1 = list1->next;
        } else {
            minValue = list2->data;
            list2 = list2->next;
        }

        Node* newNode = new Node(minValue);

        if (!mergedHead) {
            mergedHead = newNode;
            mergedTail = newNode;
        } else {
            mergedTail->next = newNode;
            mergedTail = newNode;
        }
    }

    return mergedHead;
}

// Function to print the elements of a linked list
void printLinkedList(Node* head, const string& label) {
    cout << label << ": ";
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n;
    Node* list1 = NULL;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        insertEnd(list1, value);
    }

    cin >> m;
    Node* list2 = NULL;
    for (int i = 0; i < m; ++i) {
        int value;
        cin >> value;
        insertEnd(list2, value);
    }

    // Merge and print the lists
    Node* unionList = mergeLinkedLists(list1, list2);
    printLinkedList(list1, "First Linked List");
    printLinkedList(list2, "Second Linked List");
    printLinkedList(unionList, "Union Linked List");

    return 0;
}

