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

// iterative approach of inorder traversal
void inorderTraversalIterative(Node *root)
{
    Node *curr = root;
    stack<Node *> myStack;
    while (curr || !myStack.empty())
    {
        while (curr)
        {
            myStack.push(curr);
            curr = curr->left;
        }
        curr = myStack.top();
        myStack.pop();

        cout << curr->value << " ";
        curr = curr->right;
    }
}

void preorderTraversalIterative(Node *root)
{
    Node *curr;
    stack<Node *> myStack;
    myStack.push(root);
    while (!myStack.empty())
    {
        curr = myStack.top();
        myStack.pop();
        cout << curr->value << " ";
        if (curr->right)
            myStack.push(curr->right);
        if (curr->left)
            myStack.push(curr->left);
    }
}
vector<int> postorderTraversalIterative(Node *root)
{
    Node *curr = root;
    stack<Node *> myStack;
    vector<int> output;
    myStack.push(curr);
    while (!myStack.empty())
    {
        curr = myStack.top();
        myStack.pop();
        output.push_back(curr->value);
        if (curr->left)
            myStack.push(curr->left);
        if (curr->right)
            myStack.push(curr->right);
    }
    reverse(output.begin(), output.end());
    return output;
}
void printAllPath(Node *node, vector<int> path)
{
    if (node->left == NULL && node->right == NULL)
    {
        path.push_back(node->value);
        for (auto el : path)
            cout << el << "->";
        cout << endl;
        return;
    }
    path.push_back(node->value);
    printAllPath(node->left, path);
    printAllPath(node->right, path);
}
int main()
{
    vector<int> nums = {12, 34, 11, 56, 23};
    Node *root = NULL;

    for (int el : nums)
        root = insertInBST(root, el);
    cout << "inorder traversal ";
    inorderTraversal(root);
    cout << endl;
    cout << "Inorder traversal ";

    inorderTraversalIterative(root);
    cout << endl;
    cout << "preorder traversal ";
    preorderTraversal(root);
    cout << endl;
    cout << "Preorder traversal ";
    preorderTraversalIterative(root);
    cout << endl;
    cout << "postorder traversal ";
    postorderTraversal(root);
    cout << endl;
    cout << "Postorder traversal ";
    vector<int> result = postorderTraversalIterative(root);
    for (int el : result)
        cout << el << " ";
    cout << endl;
    cout << "all path in tree " << endl;
    printAllPath(root, {});
    return 0;
}