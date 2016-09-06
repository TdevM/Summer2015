#include<iostream>
using namespace std;
struct student {
    char name[100];
    int age;
};
void readStudent(student &s) {
    cout << "Enter name";
    cin.getline(s.name, 100);
    cout << "Enter age";
    cin >> s.age;
    return;
}
void readStudent(student * st) {
    cout << "Enter name ";
    cin.getline((*st).name, 100);
    cout << "Enter age ";
    cin >> (*st).age;
}
void printStudent(const student * st) {
    st->age = 100;
    student s1;
    st = &s1;
    cout << st->name << " " << st->age << endl;
}
void printStudent(const student & st) {
    cout << st.name << "--" << st.age << endl;
}
int main() {
    student s;
    readStudent(s);
    const student & s1 = s;
    s.age = 100;
    printStudent(s);
    printStudent(s1);
    return 0;
}
