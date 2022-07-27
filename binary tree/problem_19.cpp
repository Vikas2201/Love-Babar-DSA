/* Convert Binary tree into Sum tree
(https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1) */

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

int solve(node* root)
{
    if(root == NULL)
        return 0;
    
    int left = solve(root->left);
    int right = solve(root->right);

    int sum = left + right;
    int temp = root->data;
    root->data = sum;
    sum += temp;
        
    return sum;
}

void toSumTree(node* root)
{
    if(root == NULL)
        return;        
    int ans = solve(root);
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

    toSumTree(root);
    cout<<"\nsum tree from a binary tree : ";
    postorder_traversal(root);
    
    return 0;
}