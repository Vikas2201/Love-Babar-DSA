/* Check if Binary tree is Sum tree or not
(https://practice.geeksforgeeks.org/problems/sum-tree/1) */

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

int sum(node* root)
{
    if(root == NULL)
       return  0;
    
    return root->data + sum(root->left) + sum(root->right);          
}

bool check(node* root)
{
    if(root == NULL)
        return true;
    
    if((root->left == NULL) && (root->right == NULL))
        return true;

    int temp = root->data;
       
    int sl = sum(root->left);
    int sr = sum(root->right);
       
    if((sl+sr == temp) && (check(root->right)) && (check(root->left)))
    {
        return true;
    }
        
    return false;
}

void preorder_traversal(node* root)
{
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
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

    cout<<"Preorder traversal : ";
    preorder_traversal(root);
    cout<<"\nIs Binary tree a sum tree or not : "<<check(root);
    
    return 0;
}