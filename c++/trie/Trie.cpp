#include <iostream>
#include "Trie.h"

using namespace std;

int main(){

    Trie* myTrie = new Trie();

    myTrie->insert("hello");
    cout << myTrie->search("shouldReturnFalse") << endl;
    cout << myTrie->search("hello") << endl;
    return 0;
}