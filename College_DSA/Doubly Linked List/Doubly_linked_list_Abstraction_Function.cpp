#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* previous;
	Node* next;
};

Node* head = nullptr;

void insertAtPosition(int element, int position) {
	Node* newNode = new Node{element, nullptr, nullptr};

	if (position == 0) {
		newNode->next = head;
		if (head != nullptr) {
			head->previous = newNode;
		}
		head = newNode;
		return;
	}

	Node* current = head;
	for (int i = 0; current != nullptr && i < position - 1; i++) {
		current = current->next;
	}

	if (current == nullptr) {
		delete newNode;
		cout << "Invalid position.\n";
		return;
	}

	newNode->next = current->next;
	newNode->previous = current;

	if (current->next != nullptr) {
		current->next->previous = newNode;
	}
	current->next = newNode;
}

bool deleteAtPosition(int position, int& element) {
	Node* current = head;

	for (int i = 0; current != nullptr && i < position; i++) {
		current = current->next;
	}

	if (current == nullptr) {
		return false;
	}

	element = current->data;

	if (current->previous != nullptr) {
		current->previous->next = current->next;
	} else {
		head = current->next;
	}

	if (current->next != nullptr) {
		current->next->previous = current->previous;
	}

	delete current;
	return true;
}

void search(int key) {
	Node* current = head;
	int position = 0;

	while (current != nullptr) {
		if (current->data == key) {
			cout << "Element found at position " << position << ".\n";
			return;
		}
		current = current->next;
		position++;
	}

	cout << "Element not found.\n";
}

void display() {
	Node* current = head;

	if (current == nullptr) {
		cout << "List is empty.\n";
		return;
	}

	cout << "List: ";
	while (current != nullptr) {
		cout << current->data << ' ';
		current = current->next;
	}
	cout << '\n';
}

int main() {
	int choice;

	do {
		cout << "\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		if (choice == 1) {
			int element, position;
			cout << "Enter element and position: ";
			cin >> element >> position;
			if (position < 0) {
				cout << "Invalid position.\n";
			} else {
				insertAtPosition(element, position);
			}
		} else if (choice == 2) {
			int position, element;
			cout << "Enter position: ";
			cin >> position;
			if (position < 0 || !deleteAtPosition(position, element)) {
				cout << "Invalid position.\n";
			} else {
				cout << "Deleted element: " << element << '\n';
			}
		} else if (choice == 3) {
			int key;
			cout << "Enter element: ";
			cin >> key;
			search(key);
		} else if (choice == 4) {
			display();
		} else if (choice != 5) {
			cout << "Invalid choice.\n";
		}
	} while (choice != 5);

	return 0;
}
