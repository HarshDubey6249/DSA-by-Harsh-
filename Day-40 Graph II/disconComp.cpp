#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph
{

    int V;
    list<int> *l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    void addedge(int u, int v)
    {

        l[u].push_back(v);
        l[v].push_back(u);
    }

    void dfsHelper(int u, vector<bool> &vis)
    {
        cout << u << " ";
        vis[u] = true;

        list<int> neighbour = l[u];
        for (int v : neighbour)
        {
            if (!vis[v])
            {
                dfsHelper(v, vis);
            }
        }
    }

    void dfs()
    {
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfsHelper(i, vis);
                cout << endl;
            }
        }
        cout << endl;
    }
};

int main()
{

    Graph graph(10);

    graph.addedge(0, 2);
    graph.addedge(2, 5);
    graph.addedge(1, 4);
    graph.addedge(1, 6);
    graph.addedge(4, 9);
    graph.addedge(4, 3);
    graph.addedge(3, 8);
    graph.addedge(3, 7);

    graph.dfs();

    return 0;
}