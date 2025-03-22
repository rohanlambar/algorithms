#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node *next, *prev;
    Node(int value){
        this.value = value;
        this.next = NULL;
        this.prev = NULL;
    }
}

void insertAtPos(Node *root,int pos , int value){
     if(root) return ;
     Node *curr = root;
     if(pos == 0){
        Node *newNode = new Node(value);
        newNode->next = root;
        newNode->prev = NULL;
        root
     }
     for(int i = 1;i<pos-1;i++){

     }
}