#include <iostream>
#include <queue>
#include <list>
#include <vector>
using namespace std;

class Graph
{
    int V;

    list<pair<int, int>> *l;
    bool isUndir;

public:
    Graph(int V, bool isUndir = true)
    {
        this->V = V;
        l = new list<pair<int, int>>[V];
        this->isUndir = isUndir;
    }

    void addEdge(int u, int v, int wt)
    {
        l[u].push_back(make_pair(v, wt));
        if (isUndir)
        {
            l[v].push_back(make_pair(u, wt));
        }
    }

    void Mst(int src)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> mst(V, false);
        //(wt,u)-.minheap

        pq.push(make_pair(0, src));
      
        int ans = 0;

        while (!pq.empty())
        {

            int wt = pq.top().first;
            int u = pq.top().second;

            pq.pop();

            if (!mst[u])
            {
                mst[u] = true;
                ans += wt;

                list<pair<int, int>> neighbour = l[u];

                for (pair<int, int> n : neighbour)
                {

                    int v=n.first;
                    int currwt=n.second;
                    pq.push(make_pair(currwt, v));
                }
            }
        }
        cout<<ans;
    }
};
int main()

// Prime's algorithem
{
    Graph graph(4);

    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 15);
    graph.addEdge(0, 3, 30);
    graph.addEdge(1, 3, 40);

    graph.addEdge(2, 3, 50);
    graph.Mst(0);

    return 0;
}