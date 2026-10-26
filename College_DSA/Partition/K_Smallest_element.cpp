#include <algorithm>
#include <iostream>

using namespace std;

int partition(int arr[], int low, int high) {

    int i = low + 1, j = high;
    int pivot = arr[low];

    while (i <= j) {

        while (i <= high && arr[i] <= pivot) {
            i++;
        }

        while (j >= low && arr[j] >= pivot) {
            j--;
        }

        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[low], arr[j]);
    return j;
}

void selectK(int arr[], int low, int high, int k) {

    int p = partition(arr, low, high);

    if (p == k - 1) {
        for (int i = 0; i < k; i++)
            cout << arr[i] << " ";

        return;
    }

    if (p > k - 1)
        selectK(arr, low, p - 1, k);
    else
        selectK(arr, p + 1, high, k);
}

int main() {

    int arr[] = {7, 2, 5, 3, 8, 18, 3, 10};

    int n = 8;
    int k = 4;

    cout << "4 smallest elements: ";

    selectK(arr, 0, n - 1, k);

    return 0;
}
