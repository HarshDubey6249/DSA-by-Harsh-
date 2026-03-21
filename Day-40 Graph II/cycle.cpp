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

    void addEdge(int u, int v)
    {

        l[u].push_back(v);
        l[v].push_back(u);
    }
    bool dfscycle(int src, int par, vector<bool> &vis)
    {

        vis[src] = true;

        list<int> neighbour = l[src];

        for (int v : neighbour)
        {
            if (!vis[v])
            {

                if (dfscycle(v, src, vis))
                {
                    return true;
                }
            }
            else
            {
                if (v != par)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfscycle()
    {

        vector<bool> vis(V, false);

        return dfscycle(0, -1, vis);
    }
};
int main()
{
    Graph graph(10);
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(0,7);

    graph.addEdge(1,5);
    graph.addEdge(3,4);

    cout<<graph.dfscycle()<<endl;
    

}