#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void bucketSort(int arr[], int size) {
	if (size < 2)
		return;

	int minimum = arr[0];
	int maximum = arr[0];

	for (int index = 1; index < size; index++) {
		minimum = min(minimum, arr[index]);
		maximum = max(maximum, arr[index]);
	}

	vector<vector<int>> buckets(maximum - minimum + 1);

	for (int index = 0; index < size; index++)
		buckets[arr[index] - minimum].push_back(arr[index]);

	int index = 0;
	for (vector<int>& bucket : buckets) {
		sort(bucket.begin(), bucket.end());

		for (int value : bucket)
			arr[index++] = value;
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

	bucketSort(arr, size);

	cout << "After sorting:\n";
	printArray(arr, size);

	return 0;
}
