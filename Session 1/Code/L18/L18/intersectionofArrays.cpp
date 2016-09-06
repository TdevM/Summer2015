#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;
int main() {
    unordered_set<int> S;
    vector<int> B;
//    unordered_map<int, int> M;
    int N, M, el;
    cin >> N >> M;
    for (int i =0 ; i < N; i++) {
        cin >> el;
        S.insert(el);
    }
    for (int i = 0; i < M; i++) {
        cin >> el;
        if (S.find(el) != S.end()) {
            B.push_back(el);
        }
    }

    for (int i = 0; i < B.size(); i++) {
        cout << B[i] << " ";
    }
    cout << endl;
    return 0;
}
