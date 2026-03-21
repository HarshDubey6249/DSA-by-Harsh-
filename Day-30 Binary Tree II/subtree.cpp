#include <iostream>
#include <vector>
#include <algorithm>
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

bool isidentical(Node *root, Node *subroot)
{

    if (root == NULL && subroot == NULL)
    {

        return true;
    }
    else if (root == NULL || subroot == NULL)
    {
        return false;
    }

    if (root->data != subroot->data)
    {
        return false;
    }

    return (isidentical(root->left, subroot->left) && isidentical(root->right, subroot->right));
}

bool iss(Node *root, Node *subroot)
{

    if (root == NULL && subroot == NULL)
    {

        return true;
    }
    else if (root == NULL || subroot == NULL)
    {
        return false;
    }

    if (root->data == subroot->data)
    {
        if (isidentical(root, subroot))
        {
            return true;
        }
    }

    bool left = iss(root->left, subroot);
    if (!left)
    {
        return iss(root->right, subroot);
    }

    return true;
}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node *root = buildtree(nodes);
    cout << "root =" << root->data;

    Node *subroot = new Node(2);

    subroot->left = new Node(4);
    subroot->right = new Node(4);
    cout<<endl;

    cout<<"suroot is availble in root :"<<iss(root,subroot);

    return 0;
}