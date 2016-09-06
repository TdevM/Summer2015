#include"myfirstHeaderFile.h"
int findMax(int * arr, int N) {
    int max = arr[0]; 
    for (int i = 1; i < N; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int findMin(int * arr, int N) {
    int min = arr[0]; 
    for (int i = 1; i < N; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}
