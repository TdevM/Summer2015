#include<iostream>
#include<cstring>
using namespace std;
class Student {
    char name[100];
    float cgpa;
    int age;
    const int property;
    int yob, mob, dateofb;
    char subjects[100][100];
    int subjectcount;
    float marks[100];
    int numberofbacks;
    bool isMarksEligibleForBack(float m) {
        return m < 35;
    }
    void updateBacksCountIfNeeded(float m) {
        if (isMarksEligibleForBack(m)) {
            numberofbacks++;
        }
    }
    public:
    Student() : property(10), numberofbacks(0), subjectcount(0), cgpa(0) {
        cout << "Inside constructor 1 "<< endl;
        age = 0;
        yob = 2015;
        mob = 1;
        dateofb= 1;
        strcpy(name, "");
    }
    Student(const char * n, int z) : property(z) {
        cout << "Inside constructor 2 "<< endl;
        numberofbacks = 0;
        subjectcount = 0;
        cgpa = 0;
        age = 0;
        yob = 2015;
        mob = 1;
        dateofb= 1;
        strcpy(name, n);
    }
    void updateMarksForSubject(const char * subject_name, float m) {
        for (int i =0 ; i< subjectcount; i++) {
            if(strcmp(subjects[i], subject_name) == 0) {
                marks[i] = m;
                updateBacksCountIfNeeded(m);
                return;
            }
        }
        strcpy(subjects[subjectcount], subject_name);
        marks[subjectcount] = m;
        updateBacksCountIfNeeded(m);
        subjectcount++;
    }
    void setAge(int a_value) {
        if (a_value < 0 || a_value > 100) {
            cout << "Impossible!!!" << endl;
        } else {
            age = a_value;
        }
    }
    void setName(const char * s) {
        strcpy(name,s);
    }
    const char * getName() {
        return name;
    }
    int getAge() {
        return age;
    }
    int getBacksCount() {
        return numberofbacks;
    }
};
int main() {
    Student s, s1, s3("Anushray", 100); // Student s(), s1(), s3();
    cout <<s1.getBacksCount() << endl;
    cout << s3.getName() << endl;
  /*
    cout << s.getBacksCount() << endl;
    s.updateBacksCountIfNeeded(-5) << endl;
    s.updateMarksForSubject("C++", 100);
    cout << s.getBacksCount() << endl;
    s.updateMarksForSubject("English", 21);
    cout << s.getBacksCount() << endl;
    s.updateMarksForSubject("English", 80);
    cout << s.getBacksCount() << endl;
    s.setAge(10);
    int  value = s.getAge();
    value++;
    cout << s.getAge() << endl;

    cout << s.getAge() << endl;
    s1.setAge(104);
    cout << s1.getAge() << endl;
*/
    return 0;
}







