#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void DFS(int node, vector<vector<int>>& graph, vector<bool>& visited)
{
    visited[node] = true;
    cout << node << " ";

    for(int next : graph[node])
    {
        if(!visited[next])
        {
            DFS(next, graph, visited);
        }
    }
}

void BFS(int start, vector<vector<int>>& graph)
{
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for(int next : graph[node])
        {
            if(!visited[next])
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main()
{
    int n = 6;

    vector<vector<int>> graph(n + 1);

    graph[1] = {2, 3};
    graph[2] = {1, 4, 5};
    graph[3] = {1, 6};
    graph[4] = {2};
    graph[5] = {2};
    graph[6] = {3};

    vector<bool> visited(n + 1, false);

    cout << "DFS: ";
    DFS(1, graph, visited);

    cout << "\nBFS: ";
    BFS(1, graph);

    return 0;
}