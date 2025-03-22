// this is implementation of dijkstra algorithm to find shortest path
// one node to all other node

#include <bits/stdc++.h>
using namespace std;
// graph
// node -> {node,distance}
// 0->{2,6},{1,2}
// 1->{3,5},{0,2}
// 2->{3,8},{0,6}
// 3->{4,10},{5,15},{2,8},{1,5}
// 4->{6,2},{3,10}
// 5->{6,6},{3,15}
// 6->{5,6},{4,2}
// Time complexity = O((V + E) log V)
// space complexity = O(V)
vector<int> dijkstraAlgorithm(int source, vector<vector<pair<int, int>>> &graph)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    vector<int> distance(graph.size(), INT_MAX);
    vector<bool> visited(graph.size(), false);
    minHeap.push({0, source});
    distance[source] = 0;
    while (!minHeap.empty())
    {
        int dist = minHeap.top().first;
        int node = minHeap.top().second;
        minHeap.pop();
        if (visited[node])
            continue;
        visited[node] = true;
        for (auto it : graph[node])
        {
            int nextNeighbour = it.first;
            int nextDist = it.second;
            if (dist + nextDist < distance[nextNeighbour])
            {
                distance[nextNeighbour] = dist + nextDist;
                minHeap.push({distance[nextNeighbour], nextNeighbour});
            }
        }
    }
    return distance;
}
int main()
{
    vector<vector<pair<int, int>>> graph(7, vector<pair<int, int>>());
    graph[0] = {{2, 6}, {1, 2}};
    graph[1] = {{3, 5}, {0, 2}};
    graph[2] = {{3, 8}, {0, 6}};
    graph[3] = {{4, 10}, {5, 15}, {2, 8}, {1, 5}};
    graph[4] = {{6, 2}, {3, 10}};
    graph[5] = {{6, 6}, {3, 15}};
    graph[6] = {{5, 6}, {4, 2}};

    vector<int> ans = dijkstraAlgorithm(0, graph);
    for (int i = 0; i < ans.size(); i++)
        cout << i << " = " << ans[i] << endl;
    return 0;
}