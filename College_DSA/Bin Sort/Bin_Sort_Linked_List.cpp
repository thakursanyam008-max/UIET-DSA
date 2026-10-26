#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int value){
        data = value;
        next = NULL;
    }
};

class LinkedList{
public:
    Node* head;
    Node* tail;

    LinkedList(){
        head = tail = NULL;
    }

    void push(int value){
        Node* newNode = new Node(value);

        if (head == NULL){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }
};

void binSort(int arr[], int n){
    int max = arr[0];

    for (int i = 1; i < n; i++){
        if (arr[i] > max)
            max = arr[i];
    }

    LinkedList bin[max + 1];
    for (int i = 0; i < n; i++){
        bin[arr[i]].push(arr[i]);
    }

    int index = 0;

    for (int i = 0; i <= max; i++){
        Node* temp = bin[i].head;
        while (temp != NULL){
            arr[index] = temp->data;
            index++;
            temp = temp->next;
        }
    }
}

int main(){
    int arr[] = {4, 2, 3, 1, 2, 4, 0};
    int n = 7;
    binSort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}