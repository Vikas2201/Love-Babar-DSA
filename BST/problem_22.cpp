/* Flatten BST to sorted list (https://www.geeksforgeeks.org/flatten-bst-to-sortedlist-increasing-order/) */

#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
        int data;
        node* left;
        node* right;

        node(int val)
        {
            data = val;
            left = NULL;
            right = NULL;
        }
};

void inorder(node* root,node* &temp)
{
    if(root == NULL)
        return ;
    inorder(root->left,temp);
    temp->left = NULL;
    temp->right = root;
    temp = root;
    inorder(root->right,temp);
}

node* flatten(node* root)
{
    if(root == NULL)
        return NULL;
    
    node* dummy = new node(-1);

    node* temp = dummy;

    inorder(root,temp);

    temp->left == NULL;
    temp->right == NULL;

    return dummy->right;
}

void print_flatten(node* root)
{
    if(root == NULL)
        return ;
    node* temp = root;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->right;
    }
}

int main()
{
    node* root = new node(8);
    root->left = new node(7);
    root->right = new node(10);
    root->left->left = new node(2);
    root->right->left = new node(9);
    root->right->right = new node(13);

    cout<<"print flatten of BST : ";
    print_flatten(flatten(root));

    return 0;
}
