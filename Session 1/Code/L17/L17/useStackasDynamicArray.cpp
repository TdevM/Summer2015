#include<iostream>
#include"StackasDynamicArray.h"
using namespace std;
int main() {

    StackAsDA<int> S;
//    try {
        for (int i = 0; i < 10; i++) {
            S.push(i*i);
        }
        for (int i = 0; i < 11 ; i++) {
            cout << S.top() << endl;
            S.pop();
        }
  /*  }catch (const char * msg) {
        cerr << msg << endl;
    }catch (int exceptionnumber) {
        cerr << exceptionnumber << endl;
    }*/
    /*int a = 10; int b = 0;
    cout << a/b << endl;*/
    return 0;
}   
