#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev; 
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
    ~Node() {
        // Destructor logic if needed
    }
};

class DoublyLinkedList{
    public:
    Node* head;
    Node* tail;
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }
    ~DoublyLinkedList() {
        if (head != NULL) {
            delete head;
            head = NULL;
        }
    }

    void push_front(int val) {
        Node* newnode = new Node(val);
        if (head == NULL) {
            head = tail = newnode;
        } else {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
    }

    void push_back(int val) {
        Node* newnode = new Node(val);
        if (head == NULL) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }

    void pop_front() {
        if (head == NULL) return;
        Node* temp = head;
        head = head->next;
        if (head != NULL) head->prev = NULL;
        else tail = NULL; 
        temp->next = NULL; 
        delete temp;
    }
    void pop_back() {
        if (head == NULL) return;
        Node* temp = tail;
        tail = tail->prev;
        if (tail != NULL) tail->next = NULL;
        else head = NULL; 
        temp->prev = NULL; 
        delete temp;
    }
    

};
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main(){
    DoublyLinkedList dll;
    dll.push_front(10);
    dll.push_front(20);
    dll.push_front(30);
    dll.push_front(40);
    printList(dll.head);


    return 0;

}