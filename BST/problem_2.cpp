/* Deletion of a node in a BST (https://leetcode.com/problems/delete-node-in-abst/) */

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

node* del(node* root,int key)
{
    if(root == NULL)
        return root;
    if(root->val == key)
    {
        if(root->left == NULL && root->right == NULL)
        {
            delete(root);
            return NULL;
        }
        if(root->left && root->right == NULL)
        {
            node* temp = root->left;
            delete(root);
            return temp;
        }
        if(root->right && root->left == NULL)
        {
            node* temp = root->right;
            delete(root);
            return temp;
        }
        if(root->left && root->right)
        {
            node* cur = root->right;
            while(cur->left != NULL)
            {
                cur = cur->left;
            }
            int newval = cur->val;
            root->val = newval;
                
            root->right = del(root->right, newval);
            return root;
        }
    }
    if(root->val > key)
        root->left = del(root->left, key);
    else if(root->val < key)
        root->right = del(root->right, key);
        
    return root;
}
    
node* deleteNode(node* root, int key) 
{
    return del(root,key);    
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
    cout<<"\nEnter a value that u want to delete in BST : ";
    cin>>value;

    root = deleteNode(root,value);
    cout<<"\nInorder Tree Traversal of BST : ";
    inorder(root);

    return 0;
}