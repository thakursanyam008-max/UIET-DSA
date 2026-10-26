#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void push(Node*& front, Node*& rear, int value) {
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

void pop(Node*& front, Node*& rear) {
    if (front == NULL) {
        cout << "Queue is empty" << endl;
        return;
    }

    Node* temp = front;

    cout << "Removed: " << front->data << endl;

    front = front->next;

    if (front == NULL)
        rear = NULL;

    delete temp;
}

bool Isempty(Node* front) {
    return front == NULL;
}

void display(Node* front) {
    Node* temp = front;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {

    Node* front = NULL;
    Node* rear = NULL;

    push(front, rear, 10);
    push(front, rear, 20);
    push(front, rear, 30);

    display(front);

    pop(front, rear);

    display(front);

    if (Isempty(front))
        cout << "Queue is empty";
    else
        cout << "Queue is not empty";

    return 0;
}
