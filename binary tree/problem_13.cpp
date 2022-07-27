/* Zig-Zag traversal of a binary tree
(https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1) */

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

void zig_zag(node* root)
{
    if(root == NULL)
        return ;
    
    stack<node*> s , t;
    bool left = true;
    s.push(root);
    while(!s.empty())
    {
        node* temp = s.top();
        s.pop();

        if(temp)
        {
            cout<<temp->data<<" ";
            if(left)
            {
                if(temp->left)
                    t.push(temp->left);
                if(temp->right)
                    t.push(temp->right);
            }
            else
            {
                if(temp->right)
                    t.push(temp->right);
                if(temp->left)
                    t.push(temp->left);
            }
        }
        if(s.empty())
        {
            swap(s,t);
            left = !left;
        }
    }
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

    cout<<"\nzig zag traversal of tree : ";
    zig_zag(root);
    return 0;
}