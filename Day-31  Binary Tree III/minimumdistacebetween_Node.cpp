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

Node* Lca2(Node* root,int n1,int n2){

    if(root==NULL){
        return NULL;
    }

    if(root->data ==n1||root->data==n2){
        return root;
    }

  Node* lcaleft= Lca2(root->left,n1,n2);
  Node* lcaright= Lca2(root->right,n1,n2);

  if(lcaleft!=NULL&& lcaright!=NULL){
    return root;
  }

  return lcaleft==NULL?lcaright:lcaleft;


}

int distance(Node* root,int n){
    if(root==NULL){
        return -1;

    }
    if(root->data==n){
        return 0;
    }

   int ld= distance(root->left,n);
   int rd= distance(root->right,n);

    if(ld!=-1){
        return ld+1;
    }

    if(rd!=-1){
        return rd+1;
    }

}

int min_distance_of_Node(Node* root,int n1,int n2){

    Node* LCA= Lca2(root,n1,n2);

    int distL=distance(LCA,n1);
     int distR=distance(LCA,n1);
     
     return distL+distR;
}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node *root = buildtree(nodes);
    cout << "root =" << root->data << " ";

    cout << endl;
    int n1=4;int n2=6;
   cout<< min_distance_of_Node(root,n1,n2);

    return 0;
}