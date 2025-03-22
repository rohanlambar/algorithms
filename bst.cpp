#include <bits/stdc++.h>
using namespace std;
// deleting from bst
class Node
{
public:
    int value;
    Node *left;
    Node *right;
    Node(int value)
    {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *insertInBST(Node *root, int value)
{
    if (!root)
        return new Node(value);
    Node *curr = root;
    Node *parent;
    while (curr)
    {
        parent = curr;
        if (curr->value > value)
            curr = curr->left;
        else
            curr = curr->right;
    }
    if (value < parent->value)
        parent->left = new Node(value);
    else
        parent->right = new Node(value);
    return root;
}

void inorderTraversal(Node *root)
{
    if (!root)
        return;
    inorderTraversal(root->left);
    cout << root->value << " ";
    inorderTraversal(root->right);
}
void preorderTraversal(Node *root)
{
    if (!root)
        return;
    cout << root->value << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorderTraversal(Node *root)
{
    if (!root)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->value << " ";
}
Node *searchInBST(Node *root, int key)
{
    // O(logN)
    Node *curr = root;
    while (curr)
    {
        if (curr->value < key)
            curr = curr->right;
        else if (curr->value > key)
            curr = curr->left;
        else
            return curr;
    }
    return nullptr;
}
void levelOrderTraversal(Node *root)
{
    if (!root)
        return;

    queue<Node *> myQueue;
    myQueue.push(root);
    while (!myQueue.empty())
    {

        Node *curr = myQueue.front();
        cout << curr->value << " ";
        myQueue.pop();
        if (curr->left)
            myQueue.push(curr->left);
        if (curr->right)
            myQueue.push(curr->right);
    }
}
Node *minNode(Node *root)
{
    if (!root)
        return nullptr;
    Node *curr = root;
    while (curr->left)
        curr = curr->left;
    return curr;
}
Node *maxNode(Node *root)
{
    if (!root)
        return nullptr;
    Node *curr = root;
    while (curr->right)
        curr = curr->right;
    return curr;
}
int getHeight(Node *root)
{
    if (!root)
        return 0;
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}
void printleaves(Node *root)
{
    if (!root)
        return;

    queue<Node *> myQueue;
    myQueue.push(root);
    while (!myQueue.empty())
    {

        Node *curr = myQueue.front();
        if (!curr->left && !curr->left)
            cout << curr->value << " ";
        myQueue.pop();
        if (curr->left)
            myQueue.push(curr->left);
        if (curr->right)
            myQueue.push(curr->right);
    }
}
int main()
{
    vector<int> nums = {12, 34, 11, 56, 23};
    Node *root = NULL;

    for (int el : nums)
        root = insertInBST(root, el);
    cout << "inorder ";
    inorderTraversal(root);
    cout << endl;
    cout << "preorder ";

    preorderTraversal(root);
    cout << endl;
    cout << "postorder ";
    postorderTraversal(root);
    cout << endl;
    cout << "searching 56 in tree  ";
    if (searchInBST(root, 56))
        cout << "present ";
    else
        cout << "not present";
    cout << endl;
    cout << "searching 66 in tree  ";
    if (searchInBST(root, 66))
        cout << "present ";
    else
        cout << "not present";
    cout << endl;
    cout << "level order traversal ";
    levelOrderTraversal(root);
    cout << endl;
    cout << "height of tree " << getHeight(root) << endl;
    cout << "min node in tree " << minNode(root)->value << endl;
    cout << "max node in tree " << maxNode(root)->value << endl;
    cout << "leaves in tree ";
    printleaves(root);
    cout << endl;
    return 0;
}