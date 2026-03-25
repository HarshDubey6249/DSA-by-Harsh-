#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

class Graph
{

    int V;
    vector<int> *l;
    bool isundir;

public:
    Graph(int V, bool isundir)
    {

        this->V = V;
        l = new vector<int>[V];
        this->isundir = isundir;
    }
    void addEdge(int u, int v)
    {

        l[u].push_back(v);
        if (isundir)
        {
            l[v].push_back(u);
        }
    }
void topologicalHelper(int src, vector<bool> &vis, stack<int> &s)
    {

        vis[src] = true;

        vector<int> neighbour = l[src];

        for (int v : neighbour)
        {

            if (!vis[v])
            {
                topologicalHelper(v, vis, s);
            }
        }
        s.push(src);
    }
 int topological()
    {
        vector<bool> vis(V, false);
        stack<int> s;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                topologicalHelper(i, vis, s);
            }
        }

        while (!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }
    }

    void index(vector<int> &indexing)
    {
        for (int u=0; u < V; u++)
        {

           vector<int> neighbour = l[u];
            for (int v : neighbour)
                indexing[v]++;
        }
    }

    void topologiSort2()
    {
        vector<int> indexing(V, 0);
        index(indexing);
        queue<int> q;

        for (int i = 0; i < V; i++)
        {

            if (indexing[i] == 0)
            {
                q.push(i);
            }
        }

        while (q.size() > 0)
        {
            int curr = q.front();
            q.pop();
            cout << curr << " ";
            vector<int> neighbour = l[curr];

            for (int v : neighbour)
            {
                indexing[v]--;
                if (indexing[v] == 0)
                {
                    q.push(v);
                }
            }
        }
        cout << endl;
    }
};

int main()
{
    //  Directed graph
    Graph graph(6, false); // false → directed graph

    // Adding edges

    graph.addEdge(2, 3);
    graph.addEdge(3, 1);
    graph.addEdge(4, 0);
    graph.addEdge(4, 1);
    graph.addEdge(5, 0); // creates a cycle
    graph.addEdge(5, 2);

    graph.topologiSort2();

    return 0;
}