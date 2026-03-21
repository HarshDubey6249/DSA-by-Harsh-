#include <iostream>
using namespace std;

// ================= NODE CLASS =================
// Each Node stores data and the address of the next node
class Node
{
public:
    int data;       // Value of the node
    Node *next;     // Pointer to next node

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
    Node *head;   // Points to first node
    Node *tail;   // Points to last node

public:
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

        if (head == NULL)         // if list is empty
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

    // Insert a node at a given position
    void insertLLinMiddle(int val, int pos)
    {
        Node *newnode = new Node(val);
        Node *temp = head;

        // Move to (pos-1)th node
        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "invalid pos";
                return;
            }
            temp = temp->next;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }

    // Delete first node
    void popFront()
    {
        if (head == NULL)
        {
            cout << "linked List is empty";
            return;
        }

        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    // Delete last node
    void pop_bacl()
    {
        if (head == NULL)
            return;

        Node *temp = head;

        // Move to second last node
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    // Iterative search – returns index of key
    int search(int key)
    {
        Node *temp = head;
        int idx = 0;

        while (temp != NULL)
        {
            if (temp->data == key)
            {
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }

    // Helper function for recursive search
    int helper(Node *temp, int key)
    {
        if (temp == NULL)
            return -1;

        if (temp->data == key)
            return 0;

        int idx = helper(temp->next, key);
        if (idx == -1)
            return -1;

        return idx + 1;
    }

    // Recursive search
    int searchRec(int key)
    {
        return helper(head, key);
    }

    // Returns total number of nodes
    int getSize()
    {
        int si = 0;
        Node *temp = head;

        while (temp != NULL)
        {
            temp = temp->next;
            si++;
        }
        return si;
    }

    // Remove nth node from the end
   void removenth(int n)
    {
        int size = getSize();
        Node *prev = head;

        // Move to (size - n)th node
        for (int i = 1; i < (size - n); i++)
        {
            prev = prev->next;
        }

        Node *deleteN = prev->next;
        cout << "delete n is " << deleteN->data << endl;

        prev->next = deleteN->next;
        delete deleteN;
    }

    void reverse(){

        Node *curr=head;
        Node*prev=NULL;

        while (curr!=NULL)
        {
            Node *next=curr->next;
            curr->next= prev;
            prev=curr;
            curr=next;

        }
        head=prev;
        
    }
};

// ================= MAIN FUNCTION =================
int main()
{
    List ll;
    ll.push_front(3);
    ll.push_front(4);
    ll.push_front(5);
    ll.push_front(6);
    ll.push_back(1);

    ll.print();
    cout << endl;

    ll.reverse();
    ll.print();

    return 0;
}