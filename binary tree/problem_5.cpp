/* Mirror of a tree (https://www.geeksforgeeks.org/create-a-mirror-tree-from-thegiven-binary-tree/) */

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

void mirror_tree(node* root)
{
    if(root == NULL)
        return ;
    node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    if(root->left)
        mirror_tree(root->left);
    if(root->right)
        mirror_tree(root->right);
}

void inorder(node* root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    node* root = new node(5);
    root->left = new node(3);
    root->right = new node(6);
    root->left->left = new node(2);
    root->left->right = new node(4);

    cout<<"\nInorder traversal of tree : ";
    inorder(root);
    mirror_tree(root);

    cout<<"\nInordere traversal of mirror tree : ";
    inorder(root);
    
    return 0;
}