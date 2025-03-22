// topological sort with help of kahn's algorithm

#include <bits/stdc++.h>
using namespace std;
// graph
// 0->1,2,3
// 1->3
// 2->3
// 3->
vector<int> topoSort(vector<vector<int>> &graph)
{
    // calculating indegree of each node
    int n = graph.size();
    vector<int> indegree(n, 0);
    for (auto node : graph)
    {
        for (auto neighbour : node)
        {
            indegree[neighbour]++;
        }
    }

    // adding node with indegree 0 to queue
    queue<int> myQueue;
    for (int i = 0; i < indegree.size(); i++)
    {
        if (indegree[i] == 0)
            myQueue.push(i);
    }
    // building toposort
    vector<int> topoSort;
    while (!myQueue.empty())
    {
        int curr = myQueue.front();
        topoSort.push_back(curr);
        myQueue.pop();
        for (auto neighbour : graph[curr])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
                myQueue.push(neighbour);
        }
    }
    return topoSort;
}
int main()
{
    vector<vector<int>> graph(5, vector<int>());
    graph[0] = {1, 2, 3};
    graph[1] = {3};
    graph[2] = {3};
    graph[3] = {};
    graph[4] = {};
    vector<int> ans = topoSort(graph);
    cout << "topological sort of graph with kahn's algorithm " << endl;
    for (auto el : ans)
        cout << el << " ";
}