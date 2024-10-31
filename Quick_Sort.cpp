#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
// Function to partition the array
int partition(int arr[], int low, int high) {
 int pivot = arr[high]; // Choosing the last element as pivot
 int i = (low - 1); // Index of smaller element
 for (int j = low; j < high; j++) {
 // If current element is smaller than or equal to pivot
 if (arr[j] <= pivot) {
 i++; // Increment index of smaller element
 swap(arr[i], arr[j]); // Swap
 }
 }
 swap(arr[i + 1], arr[high]); // Swap the pivot element with the element at i + 1
 return (i + 1); // Return the partitioning index
}
// Function to implement Quick Sort
void quickSort(int arr[], int low, int high) {
 if (low < high) {
 // Partition the array
 int pi = partition(arr, low, high);
 // Recursively sort elements before and after partition
 quickSort(arr, low, pi - 1);
 quickSort(arr, pi + 1, high);
 }
}
int main() {
 int arr[] = {5, 45, 49, 11, 7}; // Sample array
 int n = sizeof(arr) / sizeof(arr[0]);
 // Start time measurement
 auto start = high_resolution_clock::now();
 // Perform Quick Sort
 quickSort(arr, 0, n - 1);
 // End time measurement
 auto end = high_resolution_clock::now();
 // Calculate the duration of sorting
 auto duration = duration_cast<microseconds>(end - start);
 // Output the sorted array
 cout << "Sorted Array: ";
 for (int i = 0; i < n; i++) {
 cout << arr[i] << " ";
 }
 cout << endl;
 // Print the execution time
 cout << "Execution time: " << duration.count() << " microseconds" << endl;
 return 0;
}