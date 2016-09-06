// You need to complete this class as assignment - 10
// This is a header file for your flexible string. I have already included function declarations.
// All you need to do is complete the functions.
// Make sure to append null character to end of the array!!

#ifndef MYSTRING_H
#define MYSTRING_H
class MyString {
    char * arr;     // Pointer variable to store address of the dynamic allocated memory
    int len;        // To store length of the string
    int capcity;    // To store the capacity of the string
    public:
    // This is the zero parameterized constructor. It should create a empty string of initial length 0 and capacity 10;
    MyString() { 
    }

    // Another constructor which takes a 'C' type string [ character array terminated by Null Character] and creates an object
    // which is same as str.
    MyString(char *str) {
    }

    // Copy constructor
    MyString(MyString & b) {
    }

    // Destructor
    ~MyString() {
    }

    // Copy Assignment Operator
    void operator=(MyString & b) {
    }

    // It adds ch at the end of the string
    void append(char ch) {
    }

    // It adds all characters of 'C' type string str to the end.
    void append(char *str) {
    }

    // It adds all character of string b to the end.
    void append(MyString & b) {
    }

    // returns length of the string
    int length() {
    }

    // returns capacity of the string
    int capacity() {
    }

    // It removes the last character
    void pop_back() {
    }

    // It removes characters of the string from start to end
    void remove(int start, int end) {
    }

    // It removes characters of the string from start to len
    void remove(int start) {
    }

    // It deletes characters at the index.
    void deleteAt(int index) {
    }

    // Returns a MyString Object which has characters of this string from start to end
    MyString substring(int start, int end) {
    }

    // Returns a MyString Object which has characters of this string from start to length
    MyString substring(int start) {
    }

    // Returns character at the index
    char getAt(int index) {
    }

    // Returns first index of string b in this string after pos index
    int find(MyString &b, int pos = 0) {
    }

    // Returns first index of "C" type string str in this string after pos index
    int find(char *str, int pos = 0) {
    }

    // Compare function for "C" type string
    int compare(char * str) {
    }

    // Compare function for MyString type string
    int compare(MyString & b) {
    }
     
};
