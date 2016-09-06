#include<iostream>
#include"students.h"
using namespace std;
int main() {
    student s_list[2];
    student a, b,c,d,e;
    a.updateName();

    a.nb = &b;
    b.nb = &c;
    c.nb = &d;
    d.nb = &e;
    student *ptr = &a;

    



    cout << sizeof(float) << endl;
    cout << sizeof(address) << endl;
    cout << sizeof(student) << endl;
    cin.getline(s_list[0].first_name, 100);
    updateName(s_list[0].first_name, "Akshat Goyal");
    cout << s_list[0].first_name << endl;
    cout << s_list << endl;
    cout << sizeof(s_list[0]) << endl;
    student *stptr = s_list;
    stptr = new student;
    cin.getline(*(stptr).first_name, 100);
    cin.getline((stptr->addr).city, 100);



    (*stptr).q_completed +=5;
    cout << sizeof(stptr); 
/*    for (int i =0 ; i < 2; i++) {
        cout << "Enter Name " << endl;
        cin.getline(s_list[i].first_name, 100);
        cout << " Enter Roll Number" << endl;
        cin.getline(s_list[i].roll_num, 10);
        cout << " Enter marks " << endl;
        cin >> s_list[i].marks;
        cin.get();
        cout << " Enter street_address"  << endl;
        cin.getline(s_list[i].addr.street_address, 100);
        cout << " Enter city name " << endl;
        cin.getline(s_list[i].addr.city, 100);
        cout << " Enter pin code" << endl;
        cin>> s_list[i].addr.pincode;
        cout << " Enter questions completed(Honestly) !!!!" << endl;
        cin>> s_list[i].q_completed;
        cin.get();
    }

    address a;
    cin.getline(a.street_address, 100);
    cin.getline(a.city, 100);
    cin >> a.pincode;*/
    return 0;
}
