#include <bits/stdc++.h>
#include <unordered_map>
#include <list>

using namespace std;

class graph
{
public:
    unordered_map<int, list<int>> adj;

    void addedge(int u, int v, bool direction)
    {

        // direction = 0 graph is undirected
        // direction = 1 graph is directed

        // create and edge from u to v
        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printadjlist()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j << " , ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cout << "enter no. of nodes" << endl;
    cin >> n;

    int m;
    cout << "enter no. of edges" << endl;
    cin >> m;

    graph g;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        // creating undirected graph
        g.addedge(u, v, 0);
    }

    // printing graph
    g.printadjlist();

    return 0;
}