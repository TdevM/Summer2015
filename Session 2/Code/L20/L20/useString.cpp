#include<iostream>
#include<string>
using namespace std;
int main() {
    string s = "Coding Blocks";
    string s1 = "Anushray";
    s1+=s;
    s1+="--Coding Blocks";
    s1+='!';
    s1.append(3, '$');
    string s2 = "Anushray--Coding Blocks";
    cout << (s1 == s2) << endl;
    cout << s1 << endl;
    s[0] = 'D';
    cout << s << endl;
  //  cin >> s;
    getline(cin, s, '\n');
    cout << s << endl;
   
    return 0;
}
