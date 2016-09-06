#include<iostream>
using namespace std;
int main() {
   int a;
  int arr[10];
  /*cin >> arr[0];
  cin >> arr[1];
  cin >> arr[2];*/
  for(int i = 0; i < 10; i++) {
      cin >> arr[i];
  }
  int sum = 0;
  for (int i = 0; i < 10; i++) {
      sum = sum + arr[i];
  }
  cout << " Sum of elements is " << sum << endl;
  for(int i = 9; i >=0; i--) {
      cout << arr[i] << " ";
  }
  cout << endl;
  int largest = arr[0];
  for(int i = 1; i < 10; i++) {
      if (arr[i] > largest) {
          largest = arr[i];
      }
  }
  cout << "Largest Element is " << largest << endl;

  cout << "read number to find " ;
  int number;
  cin >> number;
  int i = 0;
  for(; i < 10; i++) {
      if (arr[i] == number) {
          cout << "found at " << i + 1 << " position " << endl;
          break;
      }
  }
  if( i == 10) {
      cout << " Not found" << endl;
  }

    return 0;
}
