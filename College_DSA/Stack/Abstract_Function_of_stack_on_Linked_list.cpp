#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insert(Node*& head, int value) {
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = head;

    head = newNode;
}

void remove(Node*& head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = head;
    head = head->next;

    delete temp;
}

bool Isempty(Node* head) {
    return head == NULL;
}

void display(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {

    Node* head = NULL;

    insert(head, 10);
    insert(head, 20);
    insert(head, 30);

    display(head);

    remove(head);

    display(head);

    if (Isempty(head))
        cout << "List is empty";
    else
        cout << "List is not empty";

    return 0;
}
