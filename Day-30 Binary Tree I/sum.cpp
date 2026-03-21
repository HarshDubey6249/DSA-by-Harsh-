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

int idx=-1;
Node *buildTree(vector<int> nodes)
{

    idx++;
    if (nodes[idx] == -1)
    {
        return NULL;
    }

    Node *currNode = new Node(nodes[idx]);

    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

int countOfNodeNode(Node *root)
{

    if (root == NULL)
    {

        return 0;
    }

    int btleft = countOfNodeNode(root->left);
   int btright = countOfNodeNode(root->right);

    int ans=(btleft+btright)+root->data;
    return ans;
}
int main()
{
  vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, 7, 8, -1,-1,-1};

//vector<int> nodes ={1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};

    Node *root = buildTree(nodes);
    cout << "root =" << root->data << endl;

   cout<<"height :"<< countOfNodeNode(root);

    return 0;
}