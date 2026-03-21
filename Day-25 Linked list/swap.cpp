#include <iostream>

using namespace std;

// ================= NODE CLASS =================
// Each Node stores data and the address of the next node
class Node
{
public:
    int data;   // Value of the node
    Node *next; // Pointer to next node

    // Constructor – creates a node with given value
    Node(int val)
    {
        data = val;
        next = NULL;
    }

    // Destructor – deletes the next node (used to free memory)
    // ~Node()
    // {
    //     if (next != NULL)
    //     {
    //         delete next;
    //         next = NULL;
    //     }
    // }
    ~Node() {}
};

// ================= LINKED LIST CLASS =================
class List

{

public:
    Node *head; // Points to first node
    Node *tail; // Points to last node

    // Constructor – creates an empty list
    List()
    {
        head = NULL;
        tail = NULL;
    }

    // Destructor – deletes entire list
    ~List()
    {
        if (head != NULL)
        {
            delete head;
            head = NULL;
        }
    }

    // Insert a node at the beginning
    void push_front(int val)
    {
        Node *newnode = new Node(val);

        if (head == NULL) // if list is empty
        {
            head = tail = newnode;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
    }

    // Insert a node at the end
    void push_back(int val)
    {
        Node *newnode = new Node(val);

        if (head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }

    // Print all elements of the linked list
    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "-->";
            temp = temp->next;
        }
    }

    int getsize(Node *head)
    {

        int size = 0;
        while (head != NULL)
        {

            size++;
            head = head->next;
        }
        return size;
    }

    void swap(Node *head, int k)
    {

        Node *start = head;
        Node *end = head;

        Node *prev1 = NULL;
        Node *prev2 = NULL;

        int size = getsize(head);

        for (int i = 0; i < k - 1; i++)

        {
            prev1 = start;
            start = start->next;
        }

        for (int i = 0; i < size - k; i++)
        {
            prev2 = end;
            end = end->next;
        }

        if (prev1 != NULL)
        {

            prev1->next = end;
        }
        else
        {
            head = prev2;
        }

        if (prev2 != NULL)
        {
            prev2->next = start;
        }
        else
        {
            head = prev1;
        }
        // Swap next pointers
        Node *temp = start->next;
        start->next = end->next;
        end->next = temp;
    }
};

int main()
{
    List ll;
    ll.push_front(8);
    ll.push_front(7);
    ll.push_front(6);
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    ll.print();

    cout << endl;

    // ll.NMnode(ll.head, 2, 2);

    ll.swap(ll.head, 2);
    ll.print();

    return 0;
}