#include <iostream>
#include <vector>
#include <string>

#include <unordered_map>
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
    void insert(string key)
    {

        Node *temp = root;
 
        for (int i = 0; i < key.size(); i++)
        {
            if (temp->childern.count(key[i]) == 0)
            {
                temp->childern[key[i]] = new Node();
            }
            temp = temp->childern[key[i]];
        }

       temp->endofword = true;
    }

    bool search(string key)
    {
        Node *temp = root;
        for (int i = 0; i < key.size(); i++)
        {
            if (temp->childern.count(key[i]))
            {
                temp = temp->childern[key[i]];
            }
            else
            {

                return false;
            }
        }

        return   temp->endofword;
    }
};
bool helper(Trie &trie,string key){
if(key.size()==0){
  return true;
}
   
    for(int i=0;i<key.size();i++ ){
          string fist=key.substr(0,i+1);
           string second=key.substr(i+1);

           if(trie.search(fist)&& helper(trie,second)){
            return true;
           }
    }
    return false;
}

int worldBreak(vector<string> word,string key){

    Trie trie;
    for(int i=0;i<word.size();i++ ){
        trie.insert(word[i]);
    }

   return helper(trie,key);
}

int main()
{

    vector<string> word = {"i", "like", "you"};

   

    cout<<worldBreak(word,"iikeyou")<<endl;


    return 0;
}