#include<iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int len1 = mid - left + 1;
    int len2 = right - mid;
    int temp1[len1], temp2[len2];
    for (int i = 0; i < len1; i++) {
        temp1[i] = arr[left + i];
    }
    for (int i = 0; i < len2; i++) {
        temp2[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0;
    while (i < len1 && j < len2) {
        if (temp1[i] <= temp2[j]) {
            arr[left++] = temp1[i++];
        } else {
            arr[left++] = temp2[j++];
        }
    }
    while (i < len1) {
        arr[left++] = temp1[i++];
    }
    while (j < len2) {
        arr[left++] = temp2[j++];
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
