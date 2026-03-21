//Invert Binary Tree

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

void leveloder(Node* root){
    if(root==NULL){
        return ;
    }

    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){

        Node* curr=q.front();
        q.pop();

        if(curr==NULL){
            cout<<endl;
            if(q.empty()){
                break;
            }

            q.push(NULL);
        }else{
            cout<<curr->data<<" ";

            if(curr->left!=NULL){
                q.push(curr->left);
            }

            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
    }

}

int invert(Node* root){

    if(root==NULL){
        return -1;
    }

    Node* left=root->left;
    
    root->left=root->right;
    root->right=left;

    

    return invert(root->left) &&
    invert(root->right);

}



int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node *root = buildtree(nodes);
    cout << "root =" << root->data << " ";

    cout << endl;
    leveloder(root);

    cout<<"=========================";

    cout<<invert(root);
    cout << endl;
    leveloder(root);
    

    return 0;
}