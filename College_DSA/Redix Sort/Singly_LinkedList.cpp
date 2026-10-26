#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

void insert(Node*& head, int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr)
        current = current->next;

    current->next = newNode;
}

int getMax(Node* head) {
    int maximum = head->data;

    for (Node* current = head; current != nullptr; current = current->next) {
        if (current->data > maximum)
            maximum = current->data;
    }

    return maximum;
}

Node* radixSort(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    int maximum = getMax(head);

    for (int place = 1; maximum / place > 0; place *= 10) {
        queue<Node*> digitQueues[10];
        Node* current = head;

        while (current != nullptr) {
            Node* nextNode = current->next;
            current->next = nullptr;

            int digit = (current->data / place) % 10;
            digitQueues[digit].push(current);
            current = nextNode;
        }

        head = nullptr;
        Node* tail = nullptr;

        for (int digit = 0; digit < 10; digit++) {
            while (!digitQueues[digit].empty()) {
                Node* node = digitQueues[digit].front();
                digitQueues[digit].pop();

                if (head == nullptr) {
                    head = node;
                    tail = node;
                }
                else {
                    tail->next = node;
                    tail = node;
                }
            }
        }
    }

    return head;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }

    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;

    insert(head, 170);
    insert(head, 45);
    insert(head, 75);
    insert(head, 90);
    insert(head, 802);
    insert(head, 24);
    insert(head, 2);
    insert(head, 66);

    cout << "Before sorting:\n";
    printList(head);

    head = radixSort(head);

    cout << "After sorting:\n";
    printList(head);

    return 0;
}