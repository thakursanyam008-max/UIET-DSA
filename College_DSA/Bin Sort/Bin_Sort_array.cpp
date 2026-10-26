#include <iostream>
#include <vector>

using namespace std;

void binSort(int arr[], int size) {
	if (size <= 1)
		return;

	int minimum = arr[0];
	int maximum = arr[0];

	for (int index = 1; index < size; index++) {
		if (arr[index] < minimum)
			minimum = arr[index];
		if (arr[index] > maximum)
			maximum = arr[index];
	}

	vector<int> bins(maximum - minimum + 1, 0);

	for (int index = 0; index < size; index++)
		bins[arr[index] - minimum]++;

	int index = 0;
	for (int value = minimum; value <= maximum; value++) {
		while (bins[value - minimum] > 0) {
			arr[index++] = value;
			bins[value - minimum]--;
		}
	}
}

void printArray(const int arr[], int size) {
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";

	cout << '\n';
}

int main() {
	int arr[] = {42, 32, 33, 52, 37, 47, 51};
	int size = sizeof(arr) / sizeof(arr[0]);

	cout << "Before sorting:\n";
	printArray(arr, size);

	binSort(arr, size);

	cout << "After sorting:\n";
	printArray(arr, size);

	return 0;
}
