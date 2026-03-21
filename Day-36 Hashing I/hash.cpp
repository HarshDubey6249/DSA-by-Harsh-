#include <iostream>
#include <vector>
using namespace std;

/*
    Node class
    Each node stores:
    - key (string)
    - value (int)
    - pointer to next node (for chaining in case of collision)
*/
class Node
{
public:
    string key; // key of the hash table entry
    int val;    // value associated with the key
    Node *next; // pointer to next node in linked list (collision handling)

    // Constructor
    Node(string key, int val)
    {
        this->key = key;
        this->val = val;
        next = NULL;
    }

    /*
        Destructor
        If a node is deleted, recursively delete the entire chain
    */
    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

/*
    HashTable class implementation using
    Separate Chaining (Linked List for collision handling)
*/
class HashTable
{
    int toSize;   // total size of hash table
    int currSize; // number of elements currently stored
    Node **table; // array of node pointers (each index stores linked list)

    /*
        Hash Function
        Converts string key into index of table
    */
    int hashFunction(string key)
    {
        int idx = 0;

        for (int i = 0; i < key.size(); i++)
        {
            // simple hashing logic
            idx = (idx + key[i] * key[i]) % toSize;
        }

        return idx;
    }

    /*
        Rehashing
        When load factor becomes large, table size is doubled
        and all elements are reinserted
    */
    void rehash()
    {
        Node **oldtable = table;
        int oldSize = toSize;

        // double table size
        toSize = 2 * toSize;

        // create new table
        table = new Node *[toSize];

        for (int i = 0; i < toSize; i++)
        {
            table[i] = NULL;
        }

        // copy old values into new table
        for (int i = 0; i < oldSize; i++)
        {
            Node *temp = oldtable[i];

            while (temp != NULL)
            {
                insert(temp->key, temp->val);
                temp = temp->next;
            }

            // delete old linked list
            if (oldtable[i] != NULL)
            {
                delete oldtable[i];
            }
        }
    }

public:
    /*
        Constructor
        Initialize hash table
    */
    HashTable(int size = 10)
    {
        toSize = size;
        currSize = 0;

        table = new Node *[toSize];

        for (int i = 0; i < toSize; i++)
        {
            table[i] = NULL;
        }
    }

    /*
        Insert function
        Adds a key-value pair into hash table
    */
    void insert(string key, int val)
    {
        // find index using hash function
        int idx = hashFunction(key);

        // create new node
        Node *newNode = new Node(key, val);

        // insert at beginning of linked list
        newNode->next = table[idx];
        table[idx] = newNode;

        currSize++;

        // calculate load factor
        double lamda = currSize / (double)toSize;

        // if load factor > 1 → rehash
        if (lamda > 1)
        {
            rehash(); // O(n)
        }
    }

    /*
        Check if a key exists
    */
    bool exists(string key)
    {
        int idx = hashFunction(key);
        Node *head = table[idx];

        while (head != NULL)
        {
            if (head->key == key)
            {
                return true;
            }

            head = head->next;
        }

        return false;
    }

    /*
        Search function
        Returns value of key
        If not found → return -1
    */
    int search(string key)
    {
        int idx = hashFunction(key);
        Node *head = table[idx];

        while (head != NULL)
        {
            if (head->key == key)
            {
                return head->val;
            }

            head = head->next;
        }

        return -1;
    }

    void remove(string key)
    {
        int idx = hashFunction(key);

        Node *head = table[idx];
        Node *prev = head;

        while (head != NULL)
        {

            if (head->key == key)
            {
                if (head == prev)
                {
                    table[idx] = head->next;
                }
                else
                {
                    prev->next = head->next;
                }
                break;
            }
            prev = head;
            head = head->next;
        }
  
    }

    /*
        Print entire hash table
        Shows index and all key-value pairs stored
    */
    void print()
    {
        for (int i = 0; i < toSize; i++)
        {
            cout << "curr index is " << i << " -> ";

            Node *temp = table[i];

            while (temp != NULL)
            {
                cout << "(" << temp->key << "," << temp->val << ") -> ";
                temp = temp->next;
            }

            cout << endl;
        }
    }
};

/*
    Main Function
    Testing the hash table
*/
int main()
{
    HashTable ht;

    ht.insert("india", 150);
    ht.insert("china", 200);
    ht.insert("usa", 180);
    ht.insert("japan", 120);
    ht.insert("germany", 90);
    ht.insert("france", 80);
    ht.insert("brazil", 110);
    ht.insert("canada", 70);
    ht.insert("australia", 60);
    ht.insert("russia", 140);

    ht.print();
    cout<<"=============================\n";
     ht.remove("usa");
     ht.print();

    return 0;
}