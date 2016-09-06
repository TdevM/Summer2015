#include<iostream>
using namespace std;
int binarysearch(int arr[], int start, int end, int ele) {
    cout << start << " " << end << endl;
    if (start > end) {
        return -1;
    }
    int mid = (start+end)/2;
    if (arr[mid] == ele) {
        return mid;
    } else if (arr[mid] > ele) {
        return binarysearch(arr, start, mid-1, ele);
    } else  {
        return binarysearch(arr, mid+1, end, ele);
    }
}
int main() {
    int arr[] = {1,2,3,4,5,6,7,8};
    int ans = binarysearch(arr, 0, 7, 2);
    cout << ans << endl;
}
