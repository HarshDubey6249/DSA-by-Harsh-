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

int main()
{

    vector<string> word = {"the", "a", "there", "their", "any", "there"};

    Trie trie;

    for (int i = 0; i < word.size(); i++)
    {
        trie.insert(word[i]);
    }

    cout<<trie.search("ay");


    return 0;
}