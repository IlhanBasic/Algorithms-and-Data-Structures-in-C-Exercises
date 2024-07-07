#include <stdio.h>
#include <stdlib.h>

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void heapifyMax(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr, i, largest);
        heapifyMax(arr, n, largest);
    }
}

void heapifyMin(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }

    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(arr, i, smallest);
        heapifyMin(arr, n, smallest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyMax(arr, n, i);
    }
}

void buildMinHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyMin(arr, n, i);
    }
}

void insert(int arr[], int n, int key) {
    arr[n] = key;
    int i = n;

    while (i != 0 && arr[i] > arr[(i - 1) / 2]) {
        swap(arr, i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}

void delete(int arr[], int n) {
    if (n <= 0 || n == 1) {
        return;
    }

    arr[0] = arr[n - 1];
    n--;
    heapifyMax(arr, n, 0);
}

void heapSort(int arr[], int n) {
    buildMaxHeap(arr, n);

    for (int i = n - 1; i > 0; i--) {
        swap(arr, 0, i);
        heapifyMax(arr, i, 0);
    }
}
#include <stdio.h>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Originalno polje: ");
    printArray(arr, n);


    // Build max heap
    buildMaxHeap(arr, n);
    printf("Max heap: ");
    printArray(arr, n);

    // Insert element
    int key = 9;
    insert(arr, n, key);
    printf("Nakon umetanja %d: ", key);
    printArray(arr, n + 1);

    // Delete root element
    delete(arr, n);
    printf("Nakon brisanja korijena: ");
    printArray(arr, n);

    // Heap sort
    heapSort(arr, n);
    printf("Heap sort: ");
    printArray(arr, n);

    return 0;
}
