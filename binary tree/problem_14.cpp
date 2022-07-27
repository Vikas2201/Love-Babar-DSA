/* Check if a tree is balanced or not
(https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1) */

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

int height(node* root)
{
    if(root == NULL)
        return 0;
    return 1 + max(height(root->left),height(root->right));
}

bool check_balanced_tree(node* root)
{
    if(root == NULL)
        return true;
    
    int lh = height(root->left);
    int rh = height(root->right);

    if(abs(lh-rh) > 1)
        return false;
    else
        return check_balanced_tree(root->left) && check_balanced_tree(root->right);
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

    cout<<"\nIs tree balanced or not : "<<check_balanced_tree(root);
    return 0;
}