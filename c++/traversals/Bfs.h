#ifndef BFS_H
#define BFS_H

#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;




class BFS {

    public:
    // Assuming given an adjList
    // print the traversals

    void iterativeBFS(unordered_map<int,vector<int>>& adjList, int start){
        unordered_set<int> visited;
        queue<int> q;
        q.push(start);
        visited.insert(start);

        while(!q.empty()){
            int node = q.front();
            cout << node << ' ';
            q.pop();

            for(auto& neighbor : adjList[node]){
                if(visited.count(neighbor) == 1){
                    continue;
                }
                q.push(neighbor);
                visited.insert(neighbor);
            }
        }
        cout << endl;
        return;
    }
    void recursiveBFSHelper(queue<int>& q, unordered_set<int>& visited, unordered_map<int,vector<int>>& adjList){
        if(q.empty()) return;

        int node = q.front();
        cout << node << ' ';
        q.pop();

        for(auto& neighbor : adjList[node]){
            if(visited.count(neighbor) == 1){
                continue;
            }
            q.push(neighbor);
            visited.insert(neighbor);
        }

        recursiveBFSHelper(q,visited,adjList);

    }

    void recursiveBFS(unordered_map<int,vector<int>>& adjList, int start){
        unordered_set<int> visited;
        queue<int> q;
        q.push(start);
        visited.insert(start);
        recursiveBFSHelper(q,visited, adjList);
        cout << endl;
        return;
    }
};


#endif