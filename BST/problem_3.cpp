/* Find min and max value in a BST
(https://practice.geeksforgeeks.org/problems/minimum-element-in-bst/1) */

#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
        int val;
        node *left , *right;

        node(int value)
        {
            val = value;
            left = NULL;
            right = NULL;
        }
};

int minValue(node* root) 
{
    // Code here
    if(root == NULL)
        return -1;
    if(root->left == NULL)
        return root->val;
    return minValue(root->left);
}

int maxValue(node* root)
{
    if(root == NULL)
        return -1;
    if(root->right == NULL)
        return root->val;
    return maxValue(root->right);
}

void inorder(node* root)
{
    if(root == NULL)
        return ;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

int main()
{
    node* root = new node(100);
    root->left = new node(20);
    root->right = new node(200);
    root->left->left = new node(10);
    root->left->right = new node(30);
    root->left->left->right = new node(40);

    cout<<"\nMinimum Value in BST : "<<minValue(root);
    cout<<"\nMaximum value in BST : "<<maxValue(root);

    cout<<"\nInorder Traversal of BST : ";
    inorder(root);

    return 0;
}