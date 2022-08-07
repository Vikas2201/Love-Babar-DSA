/* Find LCA of 2 nodes in a BST (https://practice.geeksforgeeks.org/problems/lowestcommon-ancestor-in-a-bst/1) */

#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
        int data;
        node *left , *right;

        node(int val)
        {
            data = val;
            left = NULL;
            right = NULL;
        }
};

node* LCA(node *root, int n1, int n2)
{
    if(root == NULL || root->data == n1 || root->data == n2)
        return root;

    node* lh = LCA(root->left,n1,n2);
    node* rh = LCA(root->right,n1,n2);
    if(lh && rh)
        return root;
    if(lh && rh == NULL)
        return lh;
    else
        return rh;
}

int main()
{
    node* root = new node(10);
    root->left = new node(8);
    root->right = new node(12);
    root->left->left = new node(3);

    node* temp = LCA(root,3,8);
    cout<<"LCA OF 3 AND 8 : "<<temp->data;
    return 0;
}