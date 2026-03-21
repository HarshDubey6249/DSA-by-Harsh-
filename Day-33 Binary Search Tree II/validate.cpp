#include <iostream>
#include <vector>
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

Node *Insert(Node *root, int n)
{

    if (root == NULL)
    {

        root = new Node(n);
        return root;
    }

    if (n < root->data)
    { // left

        root->left = Insert(root->left, n);
    }
    else // right
    {

        root->right = Insert(root->right, n);
    }

    return root;
}

Node *buildBST(int arr[], int n)
{

    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        root = Insert(root, arr[i]);
    }

    return root;
}
bool  helperFunction(Node* root,Node* min,Node* max){

    if(root==NULL){
        return true;
    }

    if(min!=NULL && root->data<=min->data){
        return false;
    }

    if(max!=NULL && root->data>=max->data){
        return false;
    }

    return helperFunction(root->left,min,root) && helperFunction(root->right,root,max);
}

bool validate(Node* root){

  return  helperFunction(root,NULL,NULL);
}

int main()
{
    int arr[] = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    int n = 9;

    Node *root = buildBST(arr, n);

    cout<< root->data<<endl;

      cout<< root->left->data<<endl;

        cout<<validate(root)<<endl;
        cout<<"------------------------------------------------"<<endl;

      root->left->data=15;

      cout<<endl;

      cout<<"after changing  "<< root->left->data<<endl;
    
     cout<<validate(root);

     return 0;
}
