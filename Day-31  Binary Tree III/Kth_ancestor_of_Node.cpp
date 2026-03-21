#include<iostream>
#include<vector>

using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){

        this->data=data;
         this->left=NULL;
          this->right=NULL;

    }
};

int idx=-1;
Node* buildtree(vector<int> nodes){
    idx++;

    if(nodes[idx]==-1){
        return NULL;
    }

    Node* curr=new Node(nodes[idx]);

    curr->left=buildtree(nodes);
    curr->right=buildtree(nodes);

    return curr;


}

int kth(Node* root,int node,int k){

    if(root==NULL){
        return -1;
    }

    if(root->data==node){
        return 0;
    }

    int left=kth(root->left,node,k);
    int right=kth(root->right,node,k);

    if(left== -1 && right== -1){
        return-1;
    }

    int validvalue = left == -1 ? right : left;

    if(validvalue +1==k){

        cout<<"kth ancestor : "<<root->data;

    }
    return validvalue +1;
}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node *root = buildtree(nodes);
    cout << "root =" << root->data << " ";

    cout << endl;
    kth(root,5,2);
    
    return 0;
}