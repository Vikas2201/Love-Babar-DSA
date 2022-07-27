/* Convert Binary tree into Doubly Linked List
(https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1) */

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

node* head = NULL;
node* temp = NULL;

void solve(node* root)
{
    if(root == NULL)
        return ;
    
    solve(root->left);
    if(head == NULL)
    {
        head = root;
        temp = root;
    }
    else
    {
        temp->right = root;
        root->left = temp;
        temp = root;
    }
    solve(root->right);
} 

void postorder_traversal(node* root)
{
    if(root == NULL)
        return;
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout<<root->data<<" ";
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout<<"\nPostorder traversal of tree  : ";
    postorder_traversal(root);

    solve(root);
    cout<<"\nDoubly linked list from a tree : ";
    node* temp = head;

    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->right;
    }
    
    return 0;
}