#include <sys/time.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
using namespace std;
long getTimeinMicroSeconds() {
	struct timeval start;
	gettimeofday(&start, NULL);
	return start.tv_sec * 1000000 + start.tv_usec;
}
void merge(int *arr, int start, int end) {
    int mid = (start+end)/2;
    int k = 0, i = start, j = mid+1;
    int temp[1000000];
    while(i <=mid && j <=end) {
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++; k++;
        } else {
            temp[k] = arr[j];
            j++; k++;
        }
    }
    while (i <=mid) {
        temp[k] = arr[i];
        k++;i++;
    }
    while (j <= end) {
        temp[k] = arr[j];
        k++; j++;
    }
    for (int k = start; k <= end; k++) {
        arr[k] = temp[k-start];
    }
}
void mergesort(int *arr, int start, int end) {
    if (start == end) {
        return;
    }
    int mid = (start+end)/2;
    mergesort(arr, start, mid);
    mergesort(arr, mid+1, end);
    merge(arr, start, end);

}
int main() {
    int N;
    int arr[1000000];
    long starttime, endtime;
    cout << "Enter Size of the input";
    cin >> N;
    for (int i =0 ; i < N; i++) {
        arr[i] = N-i;
    }
    starttime = getTimeinMicroSeconds();
    mergesort(arr, 0,N-1);
    endtime = getTimeinMicroSeconds();
    cout << " Time Taken = " << endtime - starttime;
/*    for(int i = 0; i <= 13; i++) {
        cout << arr[i] << " ";
    }*/

    return 0;
}
