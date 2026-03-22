#include <iostream>
#include <vector>
#include <list>
using namespace std;

//  Graph Type: Directed Graph (when isundir = false)
//  Algorithm: DFS (Depth First Search)
//  Purpose: Detect cycle in a directed graph using recursion stack (path array)

class Graph
{
    int V;              // Number of vertices
    list<int> *l;       // Adjacency list
    bool isundir;       // Flag to check if graph is undirected

public:
    Graph(int V, bool isundir = true)
    {
        this->V = V;            // Initialize vertices
        l = new list<int>[V];   // Create adjacency list
        this->isundir = isundir;
    }

    void addEdge(int u, int v)
    {
        // Add edge u → v
        l[u].push_back(v);

        // If undirected, also add v → u
        if (isundir)
        {
            l[v].push_back(u);
        }
    }
     void  allPathHelper(int src , int des,vector<bool> &vis, string &path){

        if(src==des){

            cout<<path<<des<<endl;
            return;
        }

        vis[src]=true;
        path+=to_string(src);

        list<int>neighbour=l[src];

        for(int v:neighbour){
            if(!vis[v]){
                
                allPathHelper(v,des,vis,path);
            }
         }
        path=path.substr(0,path.size()-1);
        vis[src]=false;
       

     }
    void  allPath(int src , int des ){

        vector<bool>vis(V, false);
        string path="";

        allPathHelper(src,des,vis,path);
    }

   
};

int main()
{
    //  Directed graph
    Graph graph(6, false);   // false → directed graph

    // Adding edges
    
    graph.addEdge(0, 3);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1); 
    graph.addEdge(4, 0);
    graph.addEdge(4, 1); 
    graph.addEdge(5, 0); // creates a cycle
    graph.addEdge(5, 2);

    graph.allPath(5,1);
   
    return 0;
}