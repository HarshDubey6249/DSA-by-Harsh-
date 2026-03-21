#include <iostream>
#include <list>
#include <vector>
#include <queue>
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

    void addEdge(int u, int v)
    {

        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print()
    {
        for (int u; u < V; u++)
        {
            list<int> neighbour = l[u];

            cout << u << ": ";
            for (int v : neighbour)
            {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    void bfs()
    {

        queue<int> q;
        vector<bool> vis(V, false);
        q.push(0);
        vis[0] = true;

        while (q.size() > 0)
        {
            int u = q.front();
            q.pop();
            cout << u << " ";
            list<int> neighbour = l[u];
            for (int v : neighbour)
            {
                if (!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }
};
int main()
{
    Graph graph(15);
    // graph.addedge(0, 1);
    // graph.addedge(0, 2);
    // graph.addedge(1, 3);
    // graph.addedge(2, 4);
    // graph.addedge(3, 5);
    // graph.addedge(3, 4);
    // graph.addedge(4, 5);
    // graph.addedge(5, 6);
    graph.addEdge(0, 1);
    graph.addEdge(0, 3);

    graph.addEdge(1, 2);

    
    graph.addEdge(3, 5);

    graph.addEdge(2, 5);
    graph.addEdge(2, 4);
    graph.addEdge(2, 7);

    graph.addEdge(5, 6);

    graph.addEdge(6, 10);

    graph.addEdge(4, 8);

    graph.addEdge(8, 11);

    graph.addEdge(7, 9);

    graph.addEdge(9, 11);

    graph.addEdge(10, 11);

    graph.bfs();

    return 0;
}