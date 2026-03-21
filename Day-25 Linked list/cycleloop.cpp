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

    bool cheakLoop(Node *head)
    {
        Node *slow = head;
        Node *fast = head;

        while (fast != NULL && fast->next != NULL)
        {

            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                cout << "cycle  exists\n";
                return true;
            }
        }
        cout << "cycle does not exists\n";
        return false;
    }

    // cheak if loop exist cut loop

    void removeCycle()
    {

        Node *slow = head;
        Node *fast = head;
        bool isSafe = false;

        while (fast != NULL && fast->next != NULL)
        {

            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                cout << "cycle  exists\n";
                isSafe = true;
                break;
            }
        }

        if (!isSafe)
        {
            cout << "cycle not exists\n";
            return;
        }

        slow = head;

        if (slow == fast)
        { // special case->tail head

            while (fast->next != slow)
            {
                fast = fast->next;
            }

            fast->next = NULL; // remove cycle
        }
        else
        {

            Node *pre = fast;

            while (slow != fast)
            {
                slow = slow->next;
                pre = fast;
                fast = fast->next;
            }

            pre->next = NULL; // remove cycle
        }
    }

   Node *splitLL(Node *head)
    {

        Node *slow = head;
        Node *fast = head;
        Node *prev = NULL;

        while (fast != NULL && fast->next != NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (prev != NULL)
        {
            prev->next = NULL;
        }
        return slow;
    }

    Node *merge(Node *h1, Node *h2)
    {
        if (h1 == NULL)
            return h2;
        if (h2 == NULL)
            return h1;

        if (h1->data <= h2->data)
        {
            h1->next = merge(h1->next, h2);
            return h1;
        }
        else
        {
            h2->next = merge(h1, h2->next);
            return h2;
        } 
    }

    Node *mergeSortLL(Node *head)
    {

        if (head == NULL || head->next == NULL)
            return head;

        Node *righthalf = splitLL(head);

        Node *left = mergeSortLL(head);
        Node *right = mergeSortLL(righthalf);

        // Merge both sorted halves
        return merge(left, right);
    }

    Node *reversre(Node *head)
    {
        Node *prev = NULL;
        Node *curr = head;

        while (curr != NULL)
        {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev; // precis head of reverse of ll
    }

    Node *Zigzag(Node *head)
    {

        Node *rightHead = splitLL(head);
        Node *righthalfReverse = reversre(rightHead);

        // alternate merging

        Node *left = head;
        Node *right = righthalfReverse;
        Node *tail = right;

        while (left != NULL && right != NULL)
        {

            Node *nextleft = left->next;
            Node *nextright = right->next;

            left->next = right;
            right->next = nextleft;
            tail = right;

            left = nextleft;
            right = nextright;
        }
        if (right != NULL)
        {
            tail->next = right;
        }
        return head;
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
    ll.push_front(7);
    ll.push_front(9);

    // ll.tail->next = ll.head;
    // ll.removeCycle();
    ll.print();

    // ll.tail->next = ll.head;
    cout << endl;
    // ll.cheakLoop(ll.head);

    // ll.head = ll.mergeSortLL(ll.head);
    ll.head = ll.Zigzag(ll.head);
    ll.print();

    return 0;
}