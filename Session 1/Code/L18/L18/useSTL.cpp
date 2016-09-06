#include<iostream>
#include<vector>
#include<string>
#include<list>
using namespace std;
int main() {
    string s("Welcome");
    vector<string> V(10, s);
    cout << V.size() << endl;
    list<vector<string> > L;
    L.push_front(V);
    L.push_front(V);
    L.push_front(V);
    L.push_front(V);
    list<vector<string> >::iterator it;
    for (it = L.begin();it != L.end();it++) {
        for (int i = 0; i < (*it).size(); i++) {
            cout << (*it)[i] << endl;
        }
    }

    for (int i = 0; i < V.size(); i++) {
        V[i]+=' ';
        V[i]+='A'+i;
        cout << V[i] << endl;
    }

    pair<pair<int,int>, char> P;
    pair<int, int>T(10, 20);
    P.first = T;
    P.second = 'B';


    cout << P.first.first << endl;
    cout << P.first.second << endl;
    cout << P.second << endl;
    return 0;
}
