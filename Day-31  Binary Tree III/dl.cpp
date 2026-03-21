//1325. Delete Leaves With a Given Value

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

Node* deletenode(Node* root,int tar){

    if(root==NULL){
        return NULL;
    }

    root-> left= deletenode(root->left,tar);
 root-> right= deletenode(root->right,tar);

    if((root->left==NULL && root->right==NULL)&& root->data==tar){
        return NULL;
    }
    

    return root;

}

bool helper(Node*root,Node* min,Node* max){

    if(root==NULL){
        return true;
    }

    if(min!=NULL &&min->data>root->data){
        return false;
    }

    if(max!=NULL &&max->data<root->data){
        return true;
    }

    helper(root->left,min,root);
      helper(root->right,root,max);
}


bool validate(Node*root){

    return helper(root,NULL,NULL);
}


int main()
{
    vector<int> nodes = {1, 3 ,3 ,-1, -1, 2 ,-1, -1, 3 ,-1, -1};

    Node *root = buildtree(nodes);
    cout << "root =" << root->data << " ";

    cout << endl;
    leveloder(root);

    cout<<"=========================";

    cout<<deletenode(root,3);
    cout << endl;
    leveloder(root);
    

    return 0;
}