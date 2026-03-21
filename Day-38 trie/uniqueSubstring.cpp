#include <iostream>
#include <string>
#include <unordered_map>
#include<vector>
using namespace std;

class Node
{
public:
    unordered_map<char, Node *> childern;
    bool endofword;

    Node()
    {
        endofword = false;
    }
};

class Trie
{

    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string key){
        Node* temp=root;
        for(int i=0;i<key.size();i++){

            if(temp->childern.count(key[i])==0){
                temp->childern[key[i]]=new Node();
            }

            temp= temp->childern[key[i]];
        }
        temp->endofword = true;
    }

    int helper(Node*root){
        int ans=0;

        for(pair<char,Node*>child: root->childern){
            ans+=helper(child.second);
        }
        return ans+1;
    }

    int Unique(){
        return helper(root);
    }
};

int CountUnique(string key){
    Trie trie;

    for(int i=0;i<key.size();i++){

        string str=key.substr(i);
          trie.insert(str);

    }
    
    return trie.Unique();

}

int main()
{

  string a="ababa";

 cout<< CountUnique(a);


    return 0;
}