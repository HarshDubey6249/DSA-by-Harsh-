#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

class Info {
public:
    bool isBst;
    int min;
    int max;
    int size;

    Info(bool isBst, int min, int max, int size) {
        this->isBst = isBst;
        this->min = min;
        this->max = max;
        this->size = size;
    }
};

int maxSize = 0;

Info* largestbst(Node* root) {

    // ✅ Correct base case
    if (root == NULL) {
        return new Info(true, INT_MAX, INT_MIN, 0);
    }

    Info* li = largestbst(root->left);
    Info* ri = largestbst(root->right);

    int cmin = min(root->data, min(li->min, ri->min));
    int cmax = max(root->data, max(li->max, ri->max));
    int csize = li->size + ri->size + 1;

    // ✅ Check BST condition
    if (li->isBst && ri->isBst &&
        root->data > li->max &&
        root->data < ri->min) {

        maxSize = max(maxSize, csize);
        return new Info(true, cmin, cmax, csize);
    }

    return new Info(false, cmin, cmax, csize);
}

int main() {

    Node *root = new Node(50);

    root->left = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(20);

    root->right = new Node(60);
    root->right->left = new Node(45);
    root->right->right = new Node(70);
    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);

    largestbst(root);

    cout << "Largest BST size: " << maxSize;

    return 0;
}