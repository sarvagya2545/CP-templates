#include<bits/stdc++.h>
using namespace std;

const int K = 26;

class TrieNode {
public:
    char c;
    vector<TrieNode*> next;
    TrieNode(char c) {
        this->c = c;
        this->next = vector<TrieNode*>(K, NULL);
    }
};

class Trie {
    TrieNode* head;
public:
    Trie() {
        this->head = new TrieNode('*');
    }

    void insert(string s) {
        auto curr = this->head;
        for(char c: s) {
            if(curr->next[c - 'a'] == NULL) 
                curr->next[c - 'a'] = new TrieNode(c);
            curr = curr->next[c - 'a'];
        }
    }
};