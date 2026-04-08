#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// class DisjointSet
// {

// public:
//     int n; // total number of
//     vector<int> par;
//     vector<int> rank;

//     DisjointSet(int n)
//     {
//         this->n = n;
//         for (int i = 0; i < n; i++)
//         {
//             par.push_back(i);
//             rank.push_back(0);
//         }
//     }
//     int find(int x)
//     {
//         if (par[x] == x)
//         {
//             return x;
//         }

//         return par[x] = find(par[x]); // path comarison
//     }
//     void unionByRank(int a, int b)
//     {
//         int parA = find(a);
//         int parB = find(b);

//         if (rank[parA] == rank[parB])
//         {

//             par[parB] = parA;
//             rank[parA]++;
//         }
//         else if (rank[parA] > rank[parB])
//         {
//             par[parB] = parA;
//         }
//         else
//         {
//             par[parA] = parB;
//         }
//     }

//     void info()
//     {
//         for (int i = 0; i < n; i++)
//         {

//             cout << i << " =par= " << par[i] << "-> rank=" << rank[i] << endl;
//         }
//     }
// };
// 𝗞𝗿𝘂𝘀𝗸𝗮𝗹 𝗔𝗹𝗴𝗼𝗿𝗶𝘁𝗵𝗲𝗺►
class Edge
{
public:
    int u;
    int v;
    int wt;

    Edge(int u,int v,int wt)
    {
        this->v = v;
        this->u = u;
        this->wt = wt;
    }
};

class Graph
{

public:
    int V;
    vector<Edge> edge;
    vector<int> par;
    vector<int> rank;

    Graph(int V)
    {
        this->V = V;
        for (int i = 0; i < V; i++)
        {
            par.push_back(i);
            rank.push_back(0);
        }
    }
    int find(int x)
    {
        if (par[x] == x)
        {
            return x;
        }

        return par[x] = find(par[x]); // path comarison
    }


     void unionByRank(int u, int v)
    {
        int parU = find(u);
        int parV = find(v);

        if (rank[parU] == rank[parV])
        {

            par[parV] = parU;
            rank[parU]++;
        }
        else if (rank[parU] > rank[parV])
        {
            par[parV] = parU;
        }
        else
        {
            par[parU] = parV;
        }
    }

    void addEdge(int u, int v, int wt)
    {

        edge.push_back(Edge(u, v, wt));
        
    }


    void krushals(){

        sort(edge.begin(),edge.end(),[](Edge &a,Edge &b) { return a.wt <b.wt;});
        int minCost=0;

        for(int i=0;i<edge.size();i++){
            Edge e=edge[i];

            int parU=find(e.u);
            int parV=find(e.v);

            if(parU!=parV){
                unionByRank(parU,parV);
                minCost+=e.wt;
            }
        }
        cout<<"min cost"<<minCost;
    }
};

// int main()
// {
//     DisjointSet dj(6);

//     dj.unionByRank(0, 2);
//     cout << dj.find(2) << endl;

//     dj.unionByRank(1, 3);
//     dj.unionByRank(2, 5);
//     dj.unionByRank(0, 3);

//     cout << dj.find(2) << endl;

//     dj.unionByRank(0, 4);
//      dj.info();
//     return 0;
// }

int main()
{
    Graph graph(4);
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 15);
    graph.addEdge(0, 3, 30);
    graph.addEdge(1, 3, 40);
    graph.addEdge(2, 3, 50);

    graph.krushals();
    return 0;
}