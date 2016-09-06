#include<iostream>
#include<string>
#include "CompressedTrie.h"
using namespace std;
int main() {
    string s;
    Trie T;
    for (int i =0 ; i < 10; i++) {
        cin >> s;
        T.insert(s);
    }
    for (int i =0 ; i < 10; i++) {
        cout << " Enter a word to find";
        cin >> s;
        cout << T.find(s) << endl;
    }
    return 0;
   
}
