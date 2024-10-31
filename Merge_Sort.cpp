#include <iostream>
#include <chrono> // For timing the execution
using namespace std;
using namespace std::chrono;
// Function to merge two halves
void merge(int arr[], int left, int mid, int right) {
	int n1 = mid - left + 1; // Size of left subarray
	int n2 = right - mid; // Size of right subarray
// Create temporary arrays
	int* L = new int[n1];
	int* R = new int[n2];
// Copy data to temporary arrays
	for (int i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];
// Merge the temporary arrays back into arr[left..right]
	int i = 0; // Initial index of the first subarray
	int j = 0; // Initial index of the second subarray
	int k = left; // Initial index of merged subarray
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
// Copy remaining elements of L[], if any
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
// Copy remaining elements of R[], if any
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
// Free the temporary arrays
	delete[] L;
	delete[] R;
}
// Function to implement merge sort
void mergeSort(int arr[], int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2; // To prevent overflow
// Sort first and second halves
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
// Merge the sorted halves
		merge(arr, left, mid, right);
	}
}
int main() {
	int arr[] = {5, 45, 49, 11, 7};
	int n = sizeof(arr) / sizeof(arr[0]);
// Start time
	auto start = high_resolution_clock::now();
// Perform merge sort
	mergeSort(arr, 0, n - 1);
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