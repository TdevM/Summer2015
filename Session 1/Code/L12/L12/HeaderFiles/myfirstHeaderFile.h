#ifndef MY_FIRST_HEADER_FILE_H
#define MY_FIRST_HEADER_FILE_H
int sumofArray(int * arr, int N) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += arr[i];
    }
    return sum;
}
#endif
