#ifndef STUDENTS_H
#define STUDENTS_H
#include<cstring>
struct address {
    char street_address[100];
    char city[100];
    int pincode;
};
struct student {
    char first_name[100];
    char roll_num[10];
    float marks;
    address addr;
    int q_completed;
    student  *nb;
    updateName(char * newName) {
        strcpy(first_name, newName);
    }
};
void updateName(char * first_name, char * name) {
    strcpy(s.first_name, name);
}
#endif
