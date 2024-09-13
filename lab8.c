#include <stdio.h>

// Function for Binary Search
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// Function for Interpolation Search
int interpolationSearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high && key >= arr[low] && key <= arr[high]) {
        int pos = low + (key - arr[low]) * (high - low) / (arr[high] - arr[low]);
        if (arr[pos] == key) return pos;
        else if (arr[pos] < key) low = pos + 1;
        else high = pos - 1;
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 5;

    // Binary Search
    int binaryIndex = binarySearch(arr, n, key);
    if (binaryIndex != -1)
        printf("Binary Search: Key %d found at index %d\n", key, binaryIndex);
    else
        printf("Binary Search: Key %d not found\n", key);

    // Interpolation Search
    int interpolationIndex = interpolationSearch(arr, n, key);
    if (interpolationIndex != -1)
        printf("Interpolation Search: Key %d found at index %d\n", key, interpolationIndex);
    else
        printf("Interpolation Search: Key %d not found\n", key);

    return 0;
}
