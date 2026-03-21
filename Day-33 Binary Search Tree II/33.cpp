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

Node *sortbuildBST(int arr[], int st, int end)
{

    if (st > end)
    {
        return NULL;
    }

    int mid = st + (end - st) / 2;
    Node *curr = new Node(arr[mid]);

    curr->left = sortbuildBST(arr, st, mid - 1);
    curr->right = sortbuildBST(arr, mid + 1, end);

    return curr;
}

void preorder(Node *root)
{

    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);

    preorder(root->right);
}

void getoder(Node *root, vector<int> &vec)
{

    if (root == NULL)
    {
        return;
    }
   getoder(root->left, vec);
    vec.push_back(root->data);
    getoder(root->right, vec);

}

Node *sortbuildBSTvector(vector<int> arr, int st, int end)
{

    if (st > end)
    {
        return NULL;
    }

    int mid = st + (end - st) / 2;
    Node *curr = new Node(arr[mid]);

    curr->left = sortbuildBSTvector(arr, st, mid - 1);
    curr->right = sortbuildBSTvector(arr, mid + 1, end);

    return curr;
}

Node* buildBSTforvec(Node *root){

   vector<int> nodes;

   getoder(root,nodes);
   return sortbuildBSTvector(nodes, 0,nodes.size()-1);

}

int main()
{

    // int arr[] = {3,4,5,6,7,8,9};
    // int st=0;
    // int end= sizeof(arr)/sizeof(arr[1])-1;

    //  Node *root = sortbuildBST(arr, 0,end);

    Node *root = new Node(6);

    root->left = new Node(5);
    root->left->left = new Node(4);
    root->left->left->left = new Node(3);

    root->right = new Node(7);
    root->right->right = new Node(8);
    root->right->right->right = new Node(9);

 root=buildBSTforvec(root);
    preorder(root);
    cout<<endl;
    return 0;
}