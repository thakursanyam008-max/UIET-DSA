#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

void push(int st[], int& size, int x) {
    if (size == MAX_SIZE) {
        cout << "Stack is full" << endl;
        return;
    }

    st[size++] = x;
}

void pop(int st[], int& size) {
    if (size == 0) {
        cout << "Stack is empty" << endl;
        return;
    }

    cout << "Popped: " << st[--size] << endl;
}

bool Isempty(int size) {
    return size == 0;
}

int main() {
    int st[MAX_SIZE];
    int size = 0;

    push(st, size, 10);
    push(st, size, 20);
    push(st, size, 30);

    pop(st, size);

    if (Isempty(size))
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is not empty" << endl;

    return 0;
}
