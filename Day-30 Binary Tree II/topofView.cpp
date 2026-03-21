#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>
#include<map>
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

    Node *currnode = new Node(nodes[idx]);

    currnode->left = buildtree(nodes);
    currnode->right = buildtree(nodes);

    return currnode;
}

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return max(height(root->left), height(root->right)) + 1;
}


void topview(Node* root){

    queue<pair<Node*,int>>q;   //(node,hd)  hd=horizental distance
    map<int,int>m;  // (hd,node->data);
    q.push(make_pair(root,0));  //push in queue
    while(!q.empty()){
        pair<Node* ,int>curr=q.front();

        q.pop();
        Node* currNode=curr.first;
        int currhd=curr.second;

        if(m.count(currhd)==0){
            m[currhd]=currNode->data;
        }
        if(currNode->left!=NULL){
            pair<Node*,int>left=make_pair(currNode->left,currhd-1);
            q.push(left);
        }
        if(currNode->right!=NULL){
            pair<Node*,int>right=make_pair(currNode->right,currhd+1);
            q.push(right);
        }
    }

    for(auto it:m){
        cout<<it.second;
    }

}
int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node *root = buildtree(nodes);
    cout << "root =" << root->data;

    cout<<endl;

    cout<<"top view of tree :";
    topview(root);

    return 0;
}