#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

int idx = -1;

Node *buildtree(vector<int> nodes)
{
    idx++;

    if (nodes[idx] == -1)
    {
        return NULL;
    }

    Node *curr = new Node(nodes[idx]);

    curr->left = buildtree(nodes);
    curr->right = buildtree(nodes);

    return curr;
}

bool rootTOnodepath(Node *root, int n, vector<int> &path)
{
    if(root==NULL){
        return false;
    }

    path.push_back(root->data);
    if(root->data==n){
        return true;
    }
  int isleft=  rootTOnodepath(root->left,n,path);
  int isright= rootTOnodepath(root->right,n,path);

    if(isleft || isright){
        return true;
    }
    path.pop_back();
    return false;


}

int Lowest_ommon_Ancestor(Node *root, int n1, int n2)
{

    vector<int> path1;
    vector<int> path2;

    rootTOnodepath(root, n1, path1);
    rootTOnodepath(root, n2, path2);

    int lca = -1;
    for (int i = 0, j = 0; i < path1.size()&& j < path2.size(); i++, j++)
    {

        if (path1[i] != path2[j])
        {
            return lca;
        }
        lca = path1[i];
        
    }
     return lca;
   
}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node *root = buildtree(nodes);
    cout << "root =" << root->data << " ";

    cout << endl;
    int n1=4;int n2=5;
   cout<< Lowest_ommon_Ancestor(root,n1,n2);

    return 0;
}