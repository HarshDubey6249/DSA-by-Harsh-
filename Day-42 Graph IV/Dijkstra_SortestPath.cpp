#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Edge
{
public:
    int v;
    int weight;

    Edge(int v, int weight)
    {

        this->v = v;
        this->weight = weight;
    }
};

void sortPath(int src, vector<vector<Edge>> &graph, int V)
{

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dis(V, INT16_MAX);

    pq.push(make_pair(0, src));
    dis[src] = 0;

    while (pq.size() > 0)
    {

        int u = pq.top().second;
        pq.pop();

        vector<Edge> neighrbour = graph[u];

        for (Edge e : neighrbour)
        {
            if (dis[e.v] > dis[u] + e.weight)
            {
                dis[e.v] = dis[u] + e.weight;
                pq.push(make_pair(dis[e.v], e.v));
            }
        }
    }

    for (int d : dis)
    {
        cout << d << " ";
    }
    cout << endl;
}
main()
{
    int V = 6;
    vector<vector<Edge>> graph(V);

    graph[0].push_back(Edge(1, 2));
    graph[0].push_back(Edge(2, 4));

    graph[1].push_back(Edge(2, 1));
    graph[1].push_back(Edge(3, 7));

    graph[2].push_back(Edge(4, 3));

    graph[3].push_back(Edge(5, 1));

    graph[4].push_back(Edge(3, 2));
    graph[4].push_back(Edge(2, 5));

    sortPath(2,graph,V);

    return 0;
}