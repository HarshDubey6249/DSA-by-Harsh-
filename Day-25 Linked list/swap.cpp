#include <iostream>
using namespace std;

// ================= NODE CLASS =================
// Represents a single node in the linked list
class Node
{
public:
    int data;   // Stores value
    Node *next; // Pointer to next node

    // Constructor: initialize node with value
    Node(int val)
    {
        data = val;
        next = NULL;
    }

    // Destructor (currently empty)
    ~Node() {}
};

// ================= LINKED LIST CLASS =================
class List
{
public:
    Node *head; // Points to first node
    Node *tail; // Points to last node

    // Constructor: initialize empty list
    List()
    {
        head = NULL;
        tail = NULL;
    }

    // Destructor: delete entire linked list
    ~List()
    {
        if (head != NULL)
        {
            delete head; // deletes only first node (not full list due to empty Node destructor)
            head = NULL;
        }
    }

    // Insert node at beginning
    void push_front(int val)
    {
        Node *newnode = new Node(val);

        if (head == NULL) // Empty list
        {
            head = tail = newnode;
        }
        else
        {
            newnode->next = head; // New node points to old head
            head = newnode;       // Update head
        }
    }

    // Insert node at end
    void push_back(int val)
    {
        Node *newnode = new Node(val);

        if (head == NULL) // Empty list
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode; // Old tail points to new node
            tail = newnode;       // Update tail
        }
    }

    // Print linked list
    void print()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << "-->";
            temp = temp->next;
        }
    }

    // Get size of linked list
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

    // Swap kth node from beginning with kth node from end
    void swap(Node *&head, int k)  // pass head by reference so changes reflect in original list
{
    // Step 1: Find size of linked list
    int size = getsize(head);

    // Step 2: Handle invalid cases
    if (k > size || k <= 0) return;

    // Step 3: Initialize pointers
    Node *start = head;   // k-th node from beginning
    Node *end = head;     // k-th node from end

    Node *prev1 = NULL;   // previous node of start
    Node *prev2 = NULL;   // previous node of end

    // Step 4: Move to k-th node from start
    for (int i = 1; i < k; i++)
    {
        prev1 = start;
        start = start->next;
    }

    // Step 5: Move to k-th node from end
    // (size - k + 1)-th node from beginning
    for (int i = 1; i < size - k + 1; i++)
    {
        prev2 = end;
        end = end->next;
    }

    // Step 6: If both nodes are same, no need to swap
    if (start == end) return;

    // Step 7: Fix previous pointers

    // If start is not head
    if (prev1 != NULL)
        prev1->next = end;
    else
        head = end;  // start was head → update head

    // If end is not head
    if (prev2 != NULL)
        prev2->next = start;
    else
        head = start; // end was head → update head

    // Step 8: Swap next pointers of start and end
    Node *temp = start->next;
    start->next = end->next;
    end->next = temp;
}
};

int main()
{
    List ll;

    // Creating linked list: 1 -> 2 -> 3 -> ... -> 8
    ll.push_front(8);
    ll.push_front(7);
    ll.push_front(6);
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    // Print original list
    ll.print();
    cout << endl;

    // Swap 2nd node from start and end
    ll.swap(ll.head, 2);

    // Print updated list
    ll.print();

    return 0;
}