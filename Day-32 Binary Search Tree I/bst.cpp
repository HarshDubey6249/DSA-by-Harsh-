#include <iostream>
#include<vector>
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

bool search(Node *root, int key)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data == key)
    {
        // cout<<root->data;
        return true;
    }

    if (root->data > key)
    {

        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }

    return false;
}
void inorder(Node *root)
{

    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node *Iss(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

Node *deleteNode(Node *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data > val)
    {
        root->left = deleteNode(root->left, val);
    }
    else if (root->data < val)
    {

        root->right = deleteNode(root->right, val);
    }
    else
    {
        // root==null cas1
        if (root->left == NULL && root->right == NULL)
        {

            delete (root);
            return NULL;
        }

        if (root->left == NULL || root->right == NULL)
        {
            return root->left == NULL ? root->right : root->left;
        }
        Node *IS = Iss(root->right);

        root->data = IS->data;
        root->right = deleteNode(root->right, IS->data);
    }
    return root;
}
// print in range

void range(Node *root, int start, int end)
{
    if (root == NULL)
    {
        return;
    }

    if (root->data >= start && root->data <= end)
    {
        cout << root->data << endl;
        range(root->left, start, end);
        range(root->right, start, end);
    }
    else if (root->data < start)
    {
        range(root->right, start, end);
    }
    else
    {
        range(root->left, start, end);
    }
}

//root to leaf 

void path(Node *root, vector<int> &vec){
    if(root==NULL){
        return;
    }
    

    vec.push_back(root->data);

    if(root->left==NULL && root->right == NULL){

        for(int i=0;i<vec.size();i++){
            cout<<vec[i]<<" ";
        }
       cout<<endl;
    }

    path(root->left,vec);
    path(root->right,vec);
   vec.pop_back();
   
}

bool helper(Node*root,Node* min,Node* max){

    if(root==NULL){
        return true;
    }

    if(min!=NULL &&min->data>=root->data){
        return false;
    }

    if(max!=NULL &&max->data<=root->data){
        return false;
    }

    return helper(root->left,min,root)
     && helper(root->right,root,max);
}


bool validate(Node*root){

    return helper(root,NULL,NULL);
}

int main()
{

    int arr[] = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    int n = 9;

    Node *root = buildBST(arr, n);

    // cout << root->data << endl;

    // inorder(root);
    // cout << endl;
    // cout << "case1  14" << endl;
    // deleteNode(root, 14);
    // inorder(root);
    // cout << endl;
    // cout << "case2  10" << endl;
    // deleteNode(root, 10);
    // inorder(root);
    // cout << endl;
    // cout << "case3  3" << endl;
    // deleteNode(root, 3);
    // inorder(root);

    // range(root,5,12);

    // vector<int>vec;

    // path(root,vec);
 //  root->data=15;
   cout<< validate(root);

    return 0;
}