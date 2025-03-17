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
void reverse(Node *head)
{
    if (!head)
        return;
    Node *prev = NULL;
    Node *curr = head->next;
    while (curr->next)
    {
        Node *further = curr->next;
        curr->next = prev;
        prev = curr;
        curr = further;
    }
    curr->next = prev;
    head->next = curr;
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
    cout << "initial linkedlist  ";
    ;
    printLL(head);

    insertAtHead(head, 12);
    cout << "insert 12 at head ";
    printLL(head);
    insertAtTail(head, 25);
    cout << "insert 25 at end ";
    printLL(head);
    insertInMiddle(head, 10, 100);
    cout << "insert 100 at index 0 (0-based index)  ";
    printLL(head);
    reverse(head);
    cout << "reversing a LL  ";
    printLL(head);
    return 0;
}