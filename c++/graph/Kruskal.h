#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <vector>
#include <tuple>
#include <unordered_map>
#include <queue>
using namespace std;


class Kruskal {

    public:
    // Find Minimum Spanning Tree of a connected graph 
    // tuple<weight,n1,n2>
    vector<pair<int, int>> kruskal(vector<tuple<int, int, int>>& edges, int numNodes) {

        UnionFind* uf = new UnionFind(numNodes);
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> minHeap;

        for(auto& it : edges){
            minHeap.push(it);
        }

        vector<pair<int,int>> mst;

        while(mst.size() < numNodes - 1 && !minHeap.empty()){
                auto it = minHeap.top();
                minHeap.pop();
                int weight = get<0>(it);
                int node1 = get<1>(it);
                int node2 = get<2>(it);
                if(uf->unite(node1,node2)){
                    mst.push_back({node1,node2});
                }
        }

        delete uf;
        return mst;

    }
};



class UnionFind {
    // <nodeVal,parentVal>
    unordered_map<int,int> parent;
    // <nodeVal,itsRank>
    unordered_map<int,int> rank;
    public:
    UnionFind(int nodes){
        for(int nodeVal = 0; nodeVal < nodes; nodeVal++){
            parent[nodeVal] = nodeVal;
            rank[nodeVal] = 0;
        }
    }

    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }


    bool unite(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        
        //Cycle
        if(rootX == rootY){
            return false;
        }

        if(rank[rootX] < rank[rootY]){
            parent[rootX] = rootY;
        } else if(rank[rootX] > rank[rootY]){
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX] += 1;
        }
        return true;
    }

};

#endif