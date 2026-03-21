#include <iostream>
#include <vector>
#include <list>
using namespace std;

//  Graph Type: Undirected Graph
//  Algorithm: DFS (Depth First Search)
//  Purpose: Detect cycle in an undirected graph

class Graph
{
    int V; // Number of vertices
    list<int> *l;
    bool isundir; // Adjacency list

public:
    Graph(int V, bool isundir = true)
    {
        this->V = V; // Initialize vertices
        l = new list<int>[V];
        this->isundir = isundir; // Create adjacency list
    }

    void addEdge(int u, int v)
    {
        // Add edge (undirected graph → both directions)
        l[u].push_back(v);
        if (isundir)
        {
            l[v].push_back(u);
        }
    }

    bool dfscycleDir(int src, vector<bool> &path, vector<bool> &vis)
    {
        vis[src] = true; // Mark current node as visited
        path[src] = true;

        list<int> neighbour = l[src]; // Get neighbours of src

        for (int v : neighbour)
        {
            if (!vis[v]) // If neighbour not visited
            {
                // Recur for neighbour
                if (dfscycleDir(v, path, vis))
                {
                    return true; // Cycle found
                }
            }
            else
            {
                // If visited and not parent → cycle exists
                if (path[src])
                {
                    return true;
                }
            }
        }
        return false; // No cycle found
    }

    bool dfscycleI()
    {
        vector<bool> vis(V, false); // Visited array
        vector<bool> path(V, false);

        // Start DFS from node 0 (only one component checked)
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                return dfscycleDir(i, path, vis);
            }
        }
    }
};

int main()
{
    // directed graph
    Graph graph(10, false); // Create graph with 10 nodes (0–9)

    // Adding edges
    graph.addEdge(1, 0);
    graph.addEdge(0, 2);
    graph.addEdge(2, 3);

    graph.addEdge(3, 4);

    // Check cycle (1 = true, 0 = false)
    cout << graph.dfscycleI() << endl;

    return 0;
}