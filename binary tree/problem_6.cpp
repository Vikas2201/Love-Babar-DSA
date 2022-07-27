/* Inorder Traversal of a tree both using recursion and Iteration
(https://www.techiedelight.com/inorder-tree-traversal-iterative-recursive/) */

#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
        int data;
        node* left;
        node* right;

        node(int value)
        {
            data = value;
            left = NULL;
            right = NULL;
        }
};

void inorder_traversal(node* root)
{
    if(root == NULL)
        return;
    inorder_traversal(root->left);
    cout<<root->data<<" ";
    inorder_traversal(root->right);
}

void inorder_traversal_iteration(node* root)
{
    stack<node*> stack; 
    while (!stack.empty() || root != NULL)
    {
        if (root != NULL)
        {
            stack.push(root);
            root = root->left;
        }
        else 
        {
            root = stack.top();
            stack.pop();
            cout << root->data << " ";
 
            root = root->right;
        }
    }
}

int main()
{
    node* root = new node(5);
    root->left = new node(3);
    root->right = new node(6);
    root->left->left = new node(2);
    root->left->right = new node(4);

    cout<<"\nInorder traversal of tree using recursion : ";
    inorder_traversal(root);

    cout<<"\nInorder traversal of tree using iteration : ";
    inorder_traversal_iteration(root);
    
    return 0;
}