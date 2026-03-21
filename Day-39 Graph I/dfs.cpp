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

    void dfshelper(int u,vector<bool>&vis){

       vis[u]=true;
       cout<<u<<" ";
      list<int>neighbour=l[u];
       for(int v:neighbour){

        if(!vis[v]){
            dfshelper(v,vis);

        }

       }


    }
   void dfs() {
   vector<bool>vis(7,false);
       dfshelper(0,vis);
       cout<<endl;
    }
};
int main()
{
    Graph graph(8);
    graph.addedge(0, 1);
    graph.addedge(0, 2);
    graph.addedge(1, 3);
    graph.addedge(2, 4);
    graph.addedge(3, 5);
    graph.addedge(3, 4);
    graph.addedge(4, 5);
    graph.addedge(5, 6);

    graph.dfs();

    return 0;
}