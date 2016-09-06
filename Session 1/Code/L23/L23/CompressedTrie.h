#ifndef COMPRESS_TRIE_H
#define COMPRESS_TRIE_H
#include<unordered_map>
#include<string>
using namespace std;
class Node {
    string str;
    bool isTerminal;
    unordered_map<char, Node*> children;
    public:
    Node(string s = "") :str(s), isTerminal(false)  {}
    friend class Trie;
};
class Trie {
    Node * root;
    public:
    Trie() {
        root = new Node;
    }
    bool find(string s) {
        Node *it = root;
        int i = 0;
        while (s[i] != 0) {
            int j = 0;
            while(it->str[j] && s[i] && it->str[j] == s[i]) {
                j++; i++;
            }
            if (it->str[j] == '\0' && s[i] == '\0') {
                return it->isTerminal;
            } else if (it->str[j] != '\0' && s[i] == '\0') {
                return false;
            } else if (it->str[j] != '\0' && s[i] != '\0') {
                return false;
            } else {
                if (it->children.find(s[i]) == it->children.end()) {
                    return false;
                } else {
                    it = it->children[s[i]];
                }
            }
        }
    }
    void insert(string s) {
        Node * it = root;
        int i = 0;
        while (s[i] != '\0') {
            int j = 0;
            while(it->str[j] && it->str[j] == s[i]) {
                j++; i++;
            }
            if (s[i] == '\0' && it->str[j] == '\0') {
                it->isTerminal = true;
                break;
            } else if (s[i] == '\0' && it->str[j] != '\0') {
                string remaing = it->str.substr(j);
                it->str = it->str.substr(0, j);
                Node * child = new Node(remaing);
                child->isTerminal = it->isTerminal;
                it->isTerminal = true;
                child->children = it->children;
                it->children.clear();
                it->children[remaing[0]] = child;
                
            } else if (s[i] != '\0' && it->str[j] == '\0') {
                if (it->children.find(s[i]) != it->children.end()) {
                    it = it->children[s[i]];
                    continue;
                } else {
                    Node *child2 = new Node(s.substr(i));
                    child2->isTerminal = true;
                    it->children[child2->str[0]] = child2;
                    break;
                }
            } else {
                string remaing = it->str.substr(j);
                it->str = it->str.substr(0, j);
                it->isTerminal = false;
                Node * child = new Node(remaing);
                child->isTerminal = true;
                child->children = it->children;
                it->children.clear();
                it->children[remaing[0]] = child;
                Node *child2 = new Node(s.substr(i));
                child2->isTerminal = true;
                it->children[child2->str[0]] = child2;
            }
        }
    }
};
#endif
