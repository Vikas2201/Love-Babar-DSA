/* Check if a tree is a BST or not (https://practice.geeksforgeeks.org/problems/checkfor-bst/1) */

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

bool check_BST(node* root,int min,int max)
{
    if(root == NULL)
        return true;
    if(min < root->val && max > root->val)
        return check_BST(root->left,min,root->val) && check_BST(root->right,root->val,max);
    else
        return false;
}

bool check(node* root)
{
    if(root == NULL)
        return true;
    return check_BST(root,INT_MIN,INT_MAX);
}

int main()
{
    node* root = new node(100);
    root->left = new node(20);
    root->right = new node(200);
    root->left->left = new node(10);
    root->left->right = new node(30);
    root->left->left->right = new node(40);

    cout<<"IS this tree is BST or not : "<<check(root);
    
    return 0;
}