#include <iostream>
#include <queue>

using namespace std;

int getMax(const int arr[], int size) {
    int maximum = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > maximum)
            maximum = arr[i];
    }

    return maximum;
}

void radixSort(int arr[], int size) {
    int maximum = getMax(arr, size);

    for (int place = 1; maximum / place > 0; place *= 10) {
        queue<int> digitQueues[10];

        for (int i = 0; i < size; i++) {
            int digit = (arr[i] / place) % 10;
            digitQueues[digit].push(arr[i]);
        }

        int index = 0;
        for (int digit = 0; digit < 10; digit++) {
            while (!digitQueues[digit].empty()) {
                arr[index] = digitQueues[digit].front();
                digitQueues[digit].pop();
                index++;
            }
        }
    }
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << '\n';
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting:\n";
    printArray(arr, size);

    radixSort(arr, size);

    cout << "After sorting:\n";
    printArray(arr, size);

    return 0;
}