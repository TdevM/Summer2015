#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main() {
    unordered_map<int, int> M;
    vector<int> V;
    int N, el;
    cin >> N;
    for (int i =0; i < N; i++) {
        cin >> el;
        V.push_back(el);
        if (el <= 0) {
            if (M.find(el) != M.end()) {
                M[el]++;
            } else {
                M[el] = 1;
            }
        }
    }
    for (int i =0; i< N; i++) {
        if (V[i] > 0 && M.find(-V[i])!= M.end()) {
            for (int j = 0; j < M[-V[i]]; j++) {
                cout << V[i] << " " << -V[i] << endl;
            }
        }
    }
    if (M.find(0) != M.end() && M[0] > 1) {
        int pairs = (M[0] * (M[0] - 1))/2;
        for (int i = 0; i < pairs; i++) {
            cout << 0 << " " << 0 << endl;
        }
    }
    return 0;
}
