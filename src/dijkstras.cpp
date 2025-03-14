#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <limits>
#include <stack>
#include <cmath>
#include <climits>
#include "dijkstras.h"

using namespace std;

auto cmp = [](const pair<int, int>& lhs, const pair<int, int>& rhs)
{
  return lhs.second > rhs.second;
};

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous){
    int numVertices = G.size();
    vector<int> distances(numVertices, INT_MAX);
    vector<bool> visited(numVertices, false);
    distances[source] = 0;
    previous[source] = INT_MIN;
    vector<int> nodesVisited;
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeap(cmp);
    
    minHeap.push({source, 0});
    
    while(!minHeap.empty()){
     
             
        int u = minHeap.top().first;
        minHeap.pop();
        if(visited[u]) continue;
        visited[u] = true;
        nodesVisited.push_back(u);
        print_path(nodesVisited, distances[u]);
        for(Edge edge: G[u]){
            int v = edge.dst;
            int weight = edge.weight;
            if(!visited[v] && distances[u] + weight < distances[v]){
                distances[v] = distances[u] + weight;
                previous[v] = u;
                minHeap.push({v, distances[v]});
                // print_path(distances[v]);
            }
        }
    }
    return distances;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination){
    return distances;
}

void print_path(const vector<int>& v, int total){

    
    for(auto value : v){
        cout << value << " ";
    }
    cout << "Total Cost is " << total << endl;
}