#include<iostream>
using namespace std;
int sumofArray(int *p,int N) { // int sumofArray(int p[], int N)
    int sum = 0; 
    for(int i = 0; i < N; i++) {
        sum += p[i];
        p[i] = sum;
    }
    return sum;
}
void swap(int *a , int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubblesort(int *arr, int N) {
    for(int i = 0; i < N-1; i++) {
        for(int j = 0; j <= N-2-i; j++) {
            if(*(arr+j) > *(arr + j + 1)) {
                swap(arr+j, arr+j+1);
            }
        }
    }
}
int main() {
    int x =100, *ptr;
    int p = 100, q = 200;
    int arr[] = {7,5,6,2,3,9,10};
    cout << arr << endl;
    for (int i =0 ; i < 7; i++) {
        cout << arr[i] << endl;
    }
/*    int ans = sumofArray(arr, 7);
    cout << " Sum of elmeents is" << ans << endl;
    for(int i =0 ; i < 7; i++) {
        cout << arr[i] << endl;
    }*/
    bubblesort(arr, 7);
    for(int i =0 ; i < 7; i++) {
        cout << arr[i] << endl;
    }

/*
    ptr = &x;
    *ptr = 97;
    ptr++;
    cpout << *ptr << endl;
    cout << &ptr << endl;
    cout << *ptr << endl;
    cout << *(&x) << endl;*/
    return 0;
}
