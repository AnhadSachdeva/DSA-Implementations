#ifndef TRIE_H
#define TRIE_H

#include <unordered_map>
#include <string>
using namespace std;

struct TrieNode {
    unordered_map<char,TrieNode*> children;
    bool isWord;

    TrieNode(){
        isWord = false;
    }

};


class Trie {

    TrieNode* head;
    public:
    Trie(){
        head = new TrieNode();
    }

    void insert(string word){
        TrieNode* currNode = head;
        for(auto& ch : word){
            if(currNode->children.find(ch) != currNode->children.end()){
                currNode = currNode->children[ch];
            } else {
                currNode->children[ch] = new TrieNode();
                currNode = currNode->children[ch];
            }
        }
        currNode->isWord = true;
    }

    bool search(string word){
        TrieNode* currNode = head;
        for(auto& ch : word){
            if(currNode->children.find(ch) == currNode->children.end()){
                return false;
            }
            currNode = currNode->children[ch];
        }
        return currNode->isWord;
    }

};

#endif