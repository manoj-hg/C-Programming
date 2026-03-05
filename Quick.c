#include <stdio.h>
#include <time.h>
void swap(int *a, int *b) {
 int temp = *a;
 *a = *b;
 *b = temp;
}
int partition(int arr[], int low, int high) {
 int pivot = arr[low]; // pivot as first element
 int i = low + 1;
 int j = high;
 while (1) {
 while (i <= high && arr[i] <= pivot) i++;
 while (arr[j] > pivot) j--;
 if (i < j) swap(&arr[i], &arr[j]);
 else break;
 }
 swap(&arr[low], &arr[j]);
 return j;
}
void quickSort(int arr[], int low, int high) {
 if (low < high) {
 int pi = partition(arr, low, high);
 quickSort(arr, low, pi - 1);
 quickSort(arr, pi + 1, high);
 }
}
int main() {
 int arr[] = {24, 17, 12, 22, 19, 15, 20};
 int n = sizeof(arr)/sizeof(arr[0]);
 clock_t start, end;
 double cpu_time;
 start = clock();
 quickSort(arr, 0, n-1);
 end = clock();
 cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
 printf("Quick Sorted array: ");
 for(int i = 0; i < n; i++)
 printf("%d ", arr[i]);
 printf("\nTime taken by Quick Sort: %f seconds\n", cpu_time);
 return 0;
}