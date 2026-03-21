#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
public:
     
    int data;
    Node*left;
    Node*right;

    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

int idx= -1;

Node* buildtree(vector<int> nodes){
    idx++;

 if(nodes[idx] == -1){
    return NULL;

 }

 Node* curr=new Node(nodes[idx]);

  curr->left=buildtree(nodes);
 curr->right=buildtree(nodes);

 return curr;

}

// void traversal(Node* root){

//     queue<Node*>Q;

//     Q.push(root);
//     Q.push(NULL);

//      int level = 1;

//     while(!Q.empty()){
     
//         Node* curr=Q.front();
//         Q.pop();

//         if(curr==NULL){
//             level++;
//             cout<<endl;
//             if(Q.empty()){
//                 break;
//             }
//             Q.push(NULL);
//         }else{
            
//            if(level==3){
//               cout<<curr->data<<" ";

//            }
              
            
//             if(curr->left!=NULL){
//                 Q.push(curr->left);
//             }

//             if(curr->right!=NULL){
//                 Q.push(curr->right);
//             }
//         }
//     }
   

// }



void kth_level(Node* root,int level){
    if(root==NULL){
        return;
    }
    
    if(level==3){
        cout<<root->data<<" ";
    }

    kth_level(root->left,level+1);
    kth_level(root->right,level+1);
}



int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node *root = buildtree(nodes);
    cout << "root =" << root->data<<" ";

    cout << endl;
      // traversal(root);
      kth_level(root,1);

    return 0;
}