#include <stdio.h>
#include <time.h>
// Linear Search Function
int linearSearch(int a[], int n, int key) {
int i;
 for (i = 0; i < n; i++) {
 if (a[i] == key)
 return i;
 }
 return -1;
}
// Binary Search Function
int binarySearch(int a[], int n, int key) {
 int low = 0, high = n - 1, mid;
 while (low <= high) {
 mid = (low + high) / 2;
 if (a[mid] == key)
 return mid;
 else if (a[mid] < key)
 low = mid + 1;
 else
 high = mid - 1;
 }
 return -1;
}
// Function to sort array (for binary search)
void sortArray(int a[], int n) {
 int temp,i,j;
 for (i = 0; i < n - 1; i++) {
 for (j = i + 1; j < n; j++) {
 if (a[i] > a[j]) {
 temp = a[i];
 a[i] = a[j];
 a[j] = temp;
 }
 }
 }
}
int main() {
 int a[20], n, key, pos,i;
clock_t start, end;
 double time_taken;
 // Input array
 printf("Enter number of elements: ");
 scanf("%d", &n);
 printf("Enter array elements:\n");
 for (i = 0; i < n; i++)
 scanf("%d", &a[i]);
 printf("Enter element to search: ");
 scanf("%d", &key);
 // Linear Search
 start = clock();
 pos = linearSearch(a, n, key);
 end = clock();
 time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
 if (pos != -1)
 printf("Linear Search: Element found at position %d\n", pos + 1);
 else
 printf("Linear Search: Element not found\n");
 printf("Time taken by Linear Search: %f seconds\n", time_taken);
 // Sort array for Binary Search
 sortArray(a, n);
 // Binary Search
 start = clock();
 pos = binarySearch(a, n, key);
 end = clock();
 time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
 if (pos != -1)
 printf("Binary Search: Element found at position %d\n", pos + 1);
 else
 printf("Binary Search: Element not found\n");
 printf("Time taken by Binary Search: %f seconds\n", time_taken);
 return 0;
}