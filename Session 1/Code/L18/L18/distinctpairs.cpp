#include<iostream>
#include<vector>
#include"HashTable.h"
using namespace std;
int main() {
    myUnorderedMap<int, int> M(7);
    vector<int> V;
    int N, el;
    cin >> N;
    for (int i =0; i < N; i++) {
        cin >> el;
        V.push_back(el);
        if (el <= 0) {
            if (M.contains(el)) {
                M[el]++;
            } else {
                M[el] = 1;
            }
        }
    }
    for (int i =0; i< N; i++) {
        if (V[i] > 0 && M.contains(-V[i])) {
            cout << V[i] << " " << -V[i] << endl;
            M[-V[i]]--;
            if (M[-V[i]] == 0) {
                M.erase(-V[i]);
            }
        }
    }
    if (M.contains(0) && M[0] > 1) {
        int pairs = (M[0])/2;
        for (int i = 0; i < pairs; i++) {
            cout << 0 << " " << 0 << endl;
        }
    }
    return 0;
}
