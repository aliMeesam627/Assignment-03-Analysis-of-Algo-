#include <iostream>
#include <chrono> // For timing the execution
using namespace std;
using namespace std::chrono;
int main() {
	int arr[] = {5, 45, 49, 11, 7};
	int n = sizeof(arr) / sizeof(arr[0]);
// Start time
	auto start = high_resolution_clock::now();
// Bubble Sort Algorithm
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
// Swap arr[j] and arr[j + 1]
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
// End time
	auto end = high_resolution_clock::now();

// Calculate the duration of sorting
	auto duration = duration_cast<microseconds>(end - start);
// Output the sorted array
	cout << "Sorted array: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
// Print the execution time
	cout << "Execution time: " << duration.count() << " microseconds" << endl;
	return 0;
}