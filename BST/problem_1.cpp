/* Find a value in a BST (https://www.geeksforgeeks.org/binary-search-tree-set-1-
search-and-insertion/) */

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

void search(node* root,int value)
{
    if(root == NULL)
    {
        cout<<"\nvalue does not find";
        return ;
    }
    if(root->val == value)
    {
        cout<<"\nvalue find in BST";
        return ;
    }
    if(root->val < value)
        search(root->right,value);
    else
        search(root->left,value);
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

    int value;
    cout<<"\nEnter a value that u want to find in BST : ";
    cin>>value;

    cout<<"\nInorder Tree Traversal of BST : ";
    inorder(root);

    search(root,value);
    return 0;
}