#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

void enqueue(int q[], int& size, int x) {
    if (size == MAX_SIZE) {
        cout << "Queue is full" << endl;
        return;
    }

    q[size++] = x;
}

void dequeue(int q[], int& size) {
    if (size == 0) {
        cout << "Queue is empty" << endl;
        return;
    }

    cout << "Removed: " << q[0] << endl;

    for (int index = 1; index < size; index++) {
        q[index - 1] = q[index];
    }

    size--;
}

bool Isempty(int size) {
    return size == 0;
}

int main() {
    int q[MAX_SIZE];
    int size = 0;

    enqueue(q, size, 10);
    enqueue(q, size, 20);
    enqueue(q, size, 30);

    dequeue(q, size);

    if (Isempty(size))
        cout << "Queue is empty" << endl;
    else
        cout << "Queue is not empty" << endl;

    return 0;
}
