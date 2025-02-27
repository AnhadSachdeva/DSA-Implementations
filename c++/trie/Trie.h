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


/*

Time Complexity => 
    Insert => O(C) 
    Search => O(C)
Space Complexity => O(C*W)
    - C = no of chars in a word
    - W = no of words;

*/


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