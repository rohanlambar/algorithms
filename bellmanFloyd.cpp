// this implementation of bellman-floyd algorithm

#include <bits/stdc++.h>
using namespace std;
// timecomplexity = O(V*E);
// space complexity = O(V)
vector<int> bellmanFloyd(int source, int vertex, vector<vector<int>> edges)
{
    vector<int> distance(vertex, INT_MAX);
    distance[source] = 0;
    for (int i = 0; i < vertex - 1; i++)
    {
        for (vector<int> &it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (distance[u] != INT_MAX && distance[u] + wt < distance[v])
            {
                distance[v] = distance[u] + wt;
            }
        }
    }
    // checking for negative cycle
    for (vector<int> &it : edges)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if (distance[u] != INT_MAX && distance[u] + wt < distance[v])
        {
            return {-1};
        }
    }
    return distance;
}
int main()
{
    int V = 6;
    vector<vector<int>> edges(7, vector<int>(3));
    edges[0] = {3, 2, 6};
    edges[1] = {5, 3, 1};
    edges[2] = {0, 1, 5};
    edges[3] = {1, 5, -3};
    edges[4] = {1, 2, -2};
    edges[5] = {3, 4, -2};
    edges[6] = {2, 4, 3};
    vector<int> distance = bellmanFloyd(0, V, edges);
    if (distance[0] = -1 && distance.size() == 1)
        cout << "exist negative cycle";
    else
    {
        for (int i = 0; i < distance.size(); i++)
        {
            cout << i << " = " << distance[i] << endl;
        }
    }
    return 0;
}