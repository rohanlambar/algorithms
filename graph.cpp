#include <bits/stdc++.h>
using namespace std;
void bfsTraversal(vector<vector<int>> &adjMatrix, int start, vector<bool> &visited)
{
    queue<int> myQueue;
    myQueue.push(start);
    visited[start] = true;
    while (!myQueue.empty())
    {
        int curr = myQueue.front();

        myQueue.pop();
        cout << curr << " ";
        for (auto neighbour : adjMatrix[curr])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                myQueue.push(neighbour);
            }
        }
    }
}
void dfsTraversal(vector<vector<int>> &adjMatrix, int start, vector<bool> &visited)
{
    stack<int> myStack;
    myStack.push(start);
    visited[start] = true;
    while (!myStack.empty())
    {
        int curr = myStack.top();
        cout << curr << " ";
        myStack.pop();
        for (auto neighbour : adjMatrix[curr])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                myStack.push(neighbour);
            }
        }
    }
}
int main()
{
    vector<vector<int>> adjMatrix(7);
    adjMatrix[0] = {1, 2, 3};
    adjMatrix[1] = {0, 4, 5};
    adjMatrix[2] = {0, 5, 6};
    adjMatrix[3] = {0, 6};
    adjMatrix[4] = {1};
    adjMatrix[5] = {1, 2};
    adjMatrix[6] = {2, 3};
    vector<bool> visited(7, false);
    cout << "bfs traversal ";
    bfsTraversal(adjMatrix, 0, visited);
    cout << endl;
    vector<bool> visited1(7, false);
    cout << "dfs Traversal ";

    dfsTraversal(adjMatrix, 0, visited1);
    cout << endl;
    vector<bool> vis(7, false);
    vis[0] = true;
    function<void(int)> dfs = [&](int node)
    {
        cout << node << " ";
        for (auto neighbour : adjMatrix[node])
        {
            if (!vis[neighbour])
            {
                vis[neighbour] = true;
                dfs(neighbour);
            }
        }
    };

    cout << "recursive dfs ";
    dfs(0);
    cout << endl;
    return 0;
}