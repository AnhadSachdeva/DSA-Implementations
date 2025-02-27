#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include<unordered_map>
#include <vector>
#include <queue>

using namespace std;

class Dijkstra
{

    public:
    // Computes the shortest path distances from start to all other nodes in a weighted graph.
    unordered_map<int,int> dijkstra(unordered_map<int, vector<pair<int, int>>>& graph, int start){
        unordered_map<int,int> minimumCost;
        minimumCost[start] = 0;
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,start});

        while(!pq.empty()){
            pair<int,int> temp = pq.top();
            pq.pop();
            int cost = temp.first;
            int node = temp.second;

            for(auto& it : graph[node]){
                int neighbor = it.first;
                int newCost = cost + it.second;
                if(minimumCost.find(neighbor) == minimumCost.end() || newCost < minimumCost[neighbor]){
                    minimumCost[neighbor] = newCost;
                    pq.push({newCost,neighbor});
                }
            }
        }
        return minimumCost;  // Moved outside the while loop
    }


};
#endif
