#include<iostream>
#include"../HeaderFiles/arrays.h"
#include"../HeaderFiles/myfirstHeaderFile.h"
using namespace std;
int main() {
    int arr[] = { 1,2,7,5,-10,4,-8};
    cout << sumofArray(arr,7) << endl;
    cout << findMax(arr, 7) << endl;
    cout << findMin(arr, 7) << endl;
    
    return 0;
}
