#ifndef UNIONFIND_H
#define UNIONFIND_H

#include <unordered_map>
#include <vector>

using namespace std;


/*

Time Complexity
    find => 
        - Average O(1)
        - Worst Case O(n)
    unionfy => 
         - Average O(1)
        - Worst Case O(n)
Space Complexity => O(n)
    - n = number of nodes
*/


class UnionFind {
    // <nodeVal,parentVal>
    unordered_map<int,int> parent;
    // <nodeVal,itsRank>
    unordered_map<int,int> rank;
    public:
    UnionFind(vector<int>& nodes){
        for(auto& nodeVal : nodes){
            parent[nodeVal] = nodeVal;
            rank[nodeVal] = 0;
        }
    }

    int find(int x){
        // until we find a node that is equal to itsself.
        // Basically find the parent.
        if(parent[x] != x){
            // This is called path compresiion. If we have a long tree we are basically compressing the path
            // Until we the node the is the parent and setting that value as the parent for the recursive calls.
            // So it flattens out
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Combining the two nodes parents
    void unite(int x, int y){
        int rootX = find(x);
        int rootY = find(y);

        if(rootX == rootY){
            return;
        }
        // Combine into the bigger rank
        if(rank[rootX] < rank[rootY]){
            parent[rootX] = rootY;
        } else if(rank[rootX] > rank[rootY]){
            parent[rootY] = rootX;
        } else {
            // if ranks are equal we have to pick one as the parent and we increase that rank of the chosen parent by 1;
            parent[rootY] = rootX;
            rank[rootX] += 1;
        }
    }

};

#endif