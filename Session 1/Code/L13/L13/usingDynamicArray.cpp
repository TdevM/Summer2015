#include<iostream>
#include"dynamic_array.h"
using namespace std;
int main() {

    dynamicarray d;
    dynamicarray * ptr;
    ptr = new dynamicarray(10);
    delete ptr;
    // dynamicarray d();
    dynamicarray e(10);
    e.push_back(10);
    // copy constructor

    dynamicarray r = e; // dynamicarray r(e);

    //Copy assignment operator
    d = e;



    cout << e.getCapacity() << endl;
    dynamicarray f(10,-5);
    for(int i = 0; i < f.getSize();i++) {
        cout << f.get(i) << endl;
    }

  /*  cout << d.getSize() << endl;
    for (int i = 0; i < 20; i++) {
        d.push_back(i);

    }
    cout << d.getCapacity() << endl;*/







}
