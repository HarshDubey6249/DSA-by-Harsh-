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

void BellamanFord(int src,int V,  vector<vector<Edge>> graph){
    vector<int>dist(V,INT16_MAX);
    dist[src]=0;
    for(int v=0;v<V-1;v++){

        for(int u=0;u<V;u++){

            for(Edge e:graph[u]){
                if(dist[e.v]>dist[u]+e.weight){
                    dist[e.v]=dist[u]+e.weight;
                }

            }
        }
    }

    for(int i=0;i<V;i++){
        cout<<dist[i]<<" ";    }
}


    int main(){
    //Bellman Ford Graph
    int V = 5;
    vector<vector<Edge>> graph(V);

    graph[0].push_back(Edge(1, 2));
    graph[0].push_back(Edge(2, 4));

    graph[1].push_back(Edge(2, -4));

    graph[2].push_back(Edge(3, 2));

    graph[3].push_back(Edge(4, 4));

    graph[4].push_back(Edge(1, -1));

    BellamanFord(0,V,graph);

    return 0;
}
