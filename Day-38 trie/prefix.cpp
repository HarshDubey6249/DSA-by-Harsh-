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
    int freq;
    Node()
    {
        endofword = false;
        freq=0;
    }
};
class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
        root->freq = -1;
    }
    void insert(string key)
    {

        Node *temp = root;

        for (int i = 0; i < key.size(); i++)
        {
            if (temp->childern.count(key[i]) == 0)
            {
                temp->childern[key[i]] = new Node();
                temp->childern[key[i]]->freq = 1;
            }
            else
            {
                temp->childern[key[i]]->freq++;
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

        return temp->endofword;
    }

    string getprefix(string key)
    {

        Node *temp = root;
        string prefix = "";

        for (int i = 0; i < key.size(); i++)
        {
            prefix += key[i];

            if (temp->childern[key[i]]->freq == 1)
            {
                break;
            }
            
                temp = temp->childern[key[i]];
            
        }
        return prefix;
    }
};

void prefix(vector<string> word)
{

    Trie trie;
    for (int i = 0; i < word.size(); i++)
    {

        trie.insert(word[i]);
    }

    for (int i = 0; i < word.size(); i++)
    {

        cout << trie.getprefix(word[i]) << " ";
    }
}

int main()
{

    vector<string> word = {"i", "like", "you","ian"};

    prefix(word);

    return 0;
}