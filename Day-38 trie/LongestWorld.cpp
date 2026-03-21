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

    void helper(Node*root,string &ans,string temp){

        for(pair<char,Node*>child:root->childern){

            temp+=child.first;
            if((temp.size()==ans.size()&& temp<ans)|| temp>ans){
                ans=temp;
            }

            helper(child.second,ans,temp);
            temp=temp.substr(0,temp.size()-1);
        }
        
    }

    string longestWorldend(){

        string ans="";

       helper(root,ans,"");

       return ans;
       
    }
};

string longestWorld(vector<string>dict){
    Trie trie;

    for(int i=0;i<dict.size();i++){
      
         trie.insert(dict[i]);

    }
    
    return trie.longestWorldend();
}

int main()
{

      vector<string> word = {"the", "a", "thee", "their", "any", "thee"};

  
cout<<longestWorld(word);

    return 0;
}