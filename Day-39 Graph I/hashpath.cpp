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

    void addedge(int u, int v)
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

    bool hashpatHelper(int src, int des, vector<bool> &vis)
    {

        if (src == des){
            return true;
        }

        vis[src] = true;

        list<int> neighbour = l[src];

        for (int v : neighbour)
        {
            if (!vis[v]){
                if (hashpatHelper(v,des,vis)){
                    return true;
                }
        }
    }
    
        return false;
    }
    bool hashpath(int src,int dest)
    {
        vector<bool> vis(V, false);
       return hashpatHelper( src, dest, vis);
        
    }
};
int main()
{
    Graph graph(7);
    graph.addedge(0, 1);
    graph.addedge(0, 2);
    graph.addedge(1, 3);
    graph.addedge(2, 4);
    graph.addedge(3, 5);
    graph.addedge(3, 4);
    graph.addedge(4, 5);
    graph.addedge(5, 6);

    cout<<graph.hashpath(0,5)<<endl;

    return 0;
}