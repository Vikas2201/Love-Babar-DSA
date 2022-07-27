/* Boundary traversal of a Binary tree
(https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binarytree/1) */

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

vector<int> ans;

bool isleaf(node* root)
{
    if(root->left == NULL && root->right == NULL)
        return true;
    return false;
}

void traverse_left(node* root)
{
    if(root == NULL)
        return;
    if(isleaf(root))
        return;

    ans.push_back(root->data);
    if(root->left)
        traverse_left(root->left);
    else if(root->right)
        traverse_left(root->right);
}

void traverse_leaf(node* root)
{
    if(root == NULL)
        return ;
    if(isleaf(root))
        ans.push_back(root->data);

    traverse_leaf(root->left);
    traverse_leaf(root->right);
}

void traverse_right(node* root)
{
    if(root == NULL)
        return ;
    if(isleaf(root))
        return;
    int temp = root->data;
    if(root->right)
        traverse_right(root->right);
    else if(root->left)
        traverse_leaf(root->left);
    ans.push_back(temp);
}

vector<int> boundary(node *root)
{
    if(root == NULL)
        return ans;
    if(!isleaf(root))  
        ans.push_back(root->data);
    traverse_left(root->left);
    traverse_leaf(root);
    traverse_right(root->right);
       
    return ans;
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

    cout<<"\nBoundary Traversal of a tree : ";
    vector<int> res = boundary(root);
    

    for(auto i : res)
        cout<<i<<" ";
    return 0;
}