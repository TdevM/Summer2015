#include<iostream>
#include"dynamic_array.h"
using namespace std;
template <typename T>
T sum(const dynamicarray<T> & d) {
    T S(0);
    for (int i =0; i < d.getSize();i++) {
        S = S+d[i];
    }
    return S;
}
int main() {
    dynamicarray<int> d(10, 5.5);
    myFriendFunction(d);
    cout << sum(d) << endl;
    cout << "Array is: " << d << endl;
    dynamicarray<float> f(8, 4.3);
    cout << sum(f) << endl;
    cout << d[4] << endl;
    cout << f[4]  << endl;

/*    dynamicarray d(10, 4);
    cout << &d << endl;
    cout << d.getSize() << endl;
    ((d+=25)+=23)+=97;
    cout << d.getSize() << endl;
    */
/*    int a = 10;
    cout << ++((a+=15)+=10) << endl;
    cout << a << endl;*/

/*    dynamicarray * ptr;
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
*/
  /*  cout << d.getSize() << endl;
    for (int i = 0; i < 20; i++) {
        d.push_back(i);
  
    }
    cout << d.getCapacity() << endl;*/






    
}
