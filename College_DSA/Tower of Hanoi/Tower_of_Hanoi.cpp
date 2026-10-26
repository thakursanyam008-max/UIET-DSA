#include <iostream>

using namespace std;

void toh(int n, int source, int helper, int destination) {
    if (n <= 0) {
        return;
    }

    toh(n - 1, source, destination, helper);
    cout << "Move disk " << n << " from rod " << source
         << " to rod " << destination << '\n';
    toh(n - 1, helper, source, destination);
}

int main() {
    int n;

    cout << "Enter the number of disks: ";
    cin >> n;

    if (n < 0) {
        cout << "Number of disks cannot be negative.\n";
        return 1;
    }

    toh(n, 1, 2, 3);
    return 0;
}