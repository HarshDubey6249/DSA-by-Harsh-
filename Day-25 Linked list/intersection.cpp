#include <iostream>
using namespace std;

// ================= NODE =================
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// // ================= LINKED LIST =================
// class List {
// public:
//     Node* head;
//     Node* tail;

//     List() {
//         head = tail = NULL;
//     }

//     // INSERT AT END (SAFE)
//     void push_back(int val) {
//         Node* newnode = new Node(val);
//         if (head == NULL) {
//             head = tail = newnode;
//         } else {
//             tail->next = newnode;
//             tail = newnode;
//         }
//     }

//     void print() {
//         Node* temp = head;
//         while (temp != NULL) {
//             cout << temp->data << "->";
//             temp = temp->next;
//         }
//         cout << "NULL\n";
//     }
// };

// // ================= INTERSECTION =================
// Node* getIntersection(Node* head1, Node* head2) {
//     if (!head1 || !head2) return NULL;

//     Node* a = head1;
//     Node* b = head2;

//     while (a != b) {
//         a = (a == NULL) ? head2 : a->next;
//         b = (b == NULL) ? head1 : b->next;
//     }
//     return a;
// }

// // ================= MAIN =================
// int main() {
//     List A, B;

//     // Common part
//     Node* common = new Node(6);
//     common->next = new Node(7);

//     // List A: 4->5->6->7
//     A.push_back(4);
//     A.push_back(5);
//     A.tail->next = common;

//     // List B: 1->2->3->6->7
//     B.push_back(1);
//     B.push_back(2);
//     B.push_back(3);
//     B.tail->next = common;

//     A.print();
//     B.print();

//     Node* ans = getIntersection(A.head, B.head);
//     if (ans)
//         cout << "Intersection at: " << ans->data << endl;
//     else
//         cout << "No intersection\n";

//     return 0;
// }


 int getsize(Node* head){

    int size=0;
      while (head != NULL){
       
        size++;
        head=head->next;
    }
    return size;
 }

Node* getIntersectionNode(Node* head1,Node* head2){

   int m= getsize(head1);
   int n= getsize(head2);

   Node* a=head1;
   Node* b=head2;

   int diff=abs(m-n);

   if(m>n){
    for(int i=0;i<diff;i++){
     a=a->next;
   }
}else{
     for(int i=0;i<diff;i++){
     b=b->next;
   }
}

while(a != NULL && b != NULL){
     if (a == b)
        return a;
            
   a= a->next;
    b=b->next;
}
return NULL;
}
void printList(Node* head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL\n";
}


int main()
{
    // Common part: 6 -> 7
    Node* common = new Node(6);
    common->next = new Node(7);

    // List A: 4 -> 5 -> 6 -> 7
    Node* headA = new Node(4);
    headA->next = new Node(5);
    headA->next->next = common;

    // List B: 1 -> 2 -> 3 -> 6 -> 7
    Node* headB = new Node(1);
    headB->next = new Node(2);
    headB->next->next = new Node(3);
    headB->next->next->next = common;

    printList(headA);
    printList(headB);

    Node* ans = getIntersectionNode(headA, headB);

    if (ans != NULL)
        cout << "Intersection at node: " << ans->data << endl;
    else
        cout << "No intersection\n";

    return 0;
}

