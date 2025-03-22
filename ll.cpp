#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node *next;
    Node()
    {
        this->value = -1;
        this->next = NULL;
    }
    Node(int value)
    {
        this->value = value;
        this->next = NULL;
    }
};

void insertAtHead(Node *head, int value)
{
    if (head)
    {
        Node *newNode = new Node(value);
        newNode->next = head->next;
        head->next = newNode;
    }
}

void printLL(Node *head)
{
    Node *curr = head->next;
    while (curr)
    {
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl;
}
void insertAtTail(Node *head, int value)
{
    if (!head)
        return;
    Node *curr = head->next;
    while (curr->next)
        curr = curr->next;
    Node *newNode = new Node(value);
    curr->next = newNode;
}
void insertInMiddle(Node *head, int index, int value)
{
    if (!head)
        return;
    Node *curr = head;
    for (int i = 0; i < index; i++)
    {

        if (curr->next)
            curr = curr->next;
    }
    Node *newNode = new Node(value);
    newNode->next = curr->next;
    curr->next = newNode;
}
void deleteNodeByPos(Node *head, int index)
{
    if (!head)
        return;
    Node *curr = head;
    for (int i = 0; i < index; i++)
    {

        if (curr->next)
            curr = curr->next;
    }
    if (curr->next)
        curr->next = curr->next->next;
}
void deleteNodeByVal(Node *head, int value)
{
    if (!head)
        return;
    Node *curr = head;
    while (curr->next != NULL && curr->next->value != value)
        curr = curr->next;
    if (curr->next)
        curr->next = curr->next->next;
}
void reverseLL(Node *head)
{
    Node *prev = NULL;
    Node *curr = head->next;
    while (curr)
    {
        Node *front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }
    head->next = prev;
}
void printReverse(Node *node)
{
    if (!node)
        return;
    printReverse(node->next);
    cout << node->value << " ";
}
bool detectCycle(Node *node)
{
    Node *slow = node;
    Node *fast = node;
    while (fast && fast->next)
    {

        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
            return true;
    }
    return false;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    Node *head = new Node();
    Node *prev = head;
    for (int el : nums)
    {
        Node *newNode = new Node(el);
        prev->next = newNode;
        prev = newNode;
    }
    cout << "initial linkedlist  : ";

    printLL(head);

    insertAtHead(head, 12);
    cout << "insert 12 at head : ";
    printLL(head);
    insertAtTail(head, 25);
    cout << "insert 25 at end : ";
    printLL(head);
    insertInMiddle(head, 0, 100);
    cout << "insert 100 at index 0 (0-based index)  : ";
    printLL(head);
    deleteNodeByVal(head, 25);
    cout << "delete by value 25 : ";
    printLL(head);
    deleteNodeByPos(head, 2);
    cout << "delete by position 2 : ";
    printLL(head);
    reverseLL(head);
    cout << "reverse LL : ";
    printLL(head);
    cout << "printing reverse LL: ";
    printReverse(head->next);
    cout << endl;
    cout << "does cycle exist " << detectCycle(head);
    Node *first = new Node(1);
    Node *second = new Node(3);
    Node *third = new Node(4);

    first->next = second;
    second->next = third;
    third->next = second;
    cout << endl;
    cout << "detecting cycle in new list ";
    cout << detectCycle(first);
    return 0;
}