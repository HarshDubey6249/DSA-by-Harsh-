#include<iostream>
#include<vector>
#include<algorithm>
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
Node* buildtree(vector<int>nodes){
    idx++;

    if(nodes[idx]==-1){
        return NULL;
    }

    Node* currnode= new Node(nodes[idx]);
    
    currnode->left=buildtree(nodes);
    currnode->right=buildtree(nodes);

    return currnode;

}

int height(Node* root){
    if(root==NULL){
        return 0;
    }

    return max(height(root->left), height(root->right)) +1;
}

int subtreediameter(Node* root){
if(root==NULL){
        return 0;
    }
    int currD=height(root->left)+height(root->right)+1;

    int leftsubtree= subtreediameter(root->left);
    int rightsubtree=subtreediameter(root->right);

   int  DOT=max(currD ,max(leftsubtree,rightsubtree));
   return DOT;
}

pair<int,int> dim2(Node* root){
    if(root==NULL){
        return make_pair(0,0);
    }

    pair<int,int> leftD=dim2(root->left);
    pair<int,int>rightD=dim2(root->right);

    int cuurD= leftD.second + rightD.second +1;
    int finalD=max(cuurD,max(leftD.first,rightD.first));
    int finalht=max(leftD.second,rightD.second)+1;

    return make_pair(finalD,finalht);
}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node *root = buildtree(nodes);
    cout << "root =" << root->data;

    cout<<endl;

    cout<<" rootdiameter :"<< height(root);
cout<<endl;
   // cout<<subtreediameter(root);

   cout<<"dim2 "<<dim2(root).first;

return 0;
}