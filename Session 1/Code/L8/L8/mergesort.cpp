#include<iostream>
using namespace std;
void merge(int arr[], int start, int end) {
    int mid = (start + end)/2;
    int i = start, j = mid+1, k =0;
    int temp[100];
    while (i <= mid && j <=end) {
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;k++;
        } else {
            temp[k] = arr[j];
            j++;k++;
        }
    }
    while(j <=end) {
        temp[k] = arr[j];
        k++; j++;
    }
    while(i <=mid) {
        temp[k] = arr[i];
        k++; i++;
    }
    for(int l =0; l < k; l++) {
        arr[start+l] = temp[l];
    }
}
void mergesort(int arr[], int start, int end) {
    if (start == end) return;
    int mid = (start + end)/2;
    mergesort(arr,start, mid);
    mergesort(arr, mid+1, end);
    merge(arr, start,end);
}
int main() {
    int arr[10] = {9,8,3,4,1,3,2,0,-1,-3};
    mergesort(arr, 0, 9);
    for(int i =0 ;i <=9;i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
