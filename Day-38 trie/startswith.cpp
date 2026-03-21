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
            if (temp->childern[key[i]])
            {
                temp = temp->childern[key[i]];
            }
            else
            {

                return false;
            }
        }

        return  true;
    }
};

bool start_with( vector<string> word,string key){
     Trie trie;

    for (int i = 0; i < word.size(); i++)
    {
        trie.insert(word[i]);
    }

    return trie.search(key);

}


int main()
{

    vector<string> word = {"apple", "app", "mango", "man", "woman", "there"};

    // Trie trie;

    // for (int i = 0; i < word.size(); i++)
    // {
    //     trie.insert(word[i]);
    // }

    cout<<start_with(word,"app");


    return 0;
}