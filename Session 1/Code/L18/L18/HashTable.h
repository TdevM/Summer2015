#ifndef MY_UNORDERED_MAP
#define MY_UNORDERED_MAP
#include<vector>
#include<list>
#include<string>
#include<iostream>
using namespace std;
int myHashFunction(const string & k) {
    int hash_value = 0;
    for (int i = 0; i < k.size(); i++) {
        hash_value = 37*hash_value * k[i];
    }
    return hash_value;
}
int myHashFunction(const int & k) {
    return k;
}
bool isPrime(int n) {
    if(n == 2 || n == 3)
        return true;
    if(n == 1 || n % 2 == 0)
        return false;
    for(int i = 3; i * i <= n; i += 2)
        if(n % i == 0)
            return false;
    return true;
}
int nextPrime(int n) {
    if(n % 2 == 0)
        ++n;
    for(; !isPrime(n); n += 2);
    return n;
}

template <typename key, typename value>
class myUnorderedMap {
    vector<list<pair<key, value> > > table;
    int ele_count;
    int myhash(const key & k) const {
        return myHashFunction(k) % table.size();
    }
    void expandAndRehash() {
        vector<list<pair<key, value> > > temp = table;
        clear();
        table.resize(nextPrime(2*temp.size()));
        for (int i =0; i < temp.size();i++) {
            typename list<pair<key, value> >::iterator it = temp[i].begin();
            for(; it!= temp[i].end();it++) {
                insertOrUpdate(it->first, it->second);
            }
        }
    }
    public:
    myUnorderedMap(int size = 101) {
        table.resize(101);
    }
    void insertOrUpdate(const key & k, const value & v) {
        list<pair<key, value> > & L = table[myhash(k)];
        typename list<pair<key, value> >::iterator it = L.begin();
        for(;it != L.end(); it++) {
            if (it->first == k) {
                it->second = v;
                return;
            }
        }
        pair<key, value> P(k, v);
        L.push_back(P);
        ele_count++;
        if (ele_count == table.size()) {
            expandAndRehash();
        }
        return;
    }
    void clear() {
        for (int i = 0; i < table.size(); i++) {
            table[i].clear();
        }
        ele_count = 0;
    }
    bool isEmpty() const {
        return ele_count == 0;
    }
    value & at(const key & k) {
        list<pair<key, value> > & L = table[myhash(k)];
        typename list<pair<key, value> >::iterator it = L.begin();
        for(;it != L.end(); it++) {
            if (it->first == k) {
                return it->second;
            }
        }
        throw "Key doesn't exist";
    }
    const value & at(const key &k) const {
        const list<pair<key, value> > & L = table[myhash(k)];
        typename list<pair<key, value> >::const_iterator it = L.begin();
        for(;it != L.end(); it++) {
            if (it->first == k) {
                return it->second;
            }
        }
        throw "Key doesn't exist";
    }
    void erase(const key & k) {
        list<pair<key, value> > & L = table[myhash(k)];
        typename list<pair<key, value> >::iterator it = L.begin();
        for(;it != L.end(); it++) {
            if (it->first == k) {
                break;
            }
        }
        if (it == L.end()) {
            throw "Key doesn't exist";
        } else {
            L.erase(it);
        }
    }
    bool contains(const key & k) const {
        const list<pair<key, value> > & L = table[myhash(k)];
        typename list<pair<key, value> >::const_iterator it = L.begin();
        for(;it != L.end(); it++) {
            if (it->first == k) {
                return true;
            }
        }
        return false;
    }
    const value & operator[](const key & k) const {
        return at(k);
    }
    value & operator[](const key & k) {
        if (contains(k)) {
            return at(k);
        } else {
            pair<key, value> P;
            P.first = k;
            insertOrUpdate(P.first, P.second);
//            return P.second;
            return at(k);
        }
    }
};
#endif
