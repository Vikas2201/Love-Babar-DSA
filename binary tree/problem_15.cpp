/* Diagnol Traversal of a Binary tree (https://www.geeksforgeeks.org/diagonaltraversal-of-binary-tree/) */

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

void diagonal_traversal(node* root,int d,map<int,vector<int>>& mp)
{
    if(root == NULL)
        return ;
    mp[d].push_back(root->data);
    diagonal_traversal(root->left,d+1,mp);
    diagonal_traversal(root->right,d,mp);
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

    map<int,vector<int>> mp;
    cout<<"\nDiagonal Traversal of a tree : ";
    diagonal_traversal(root,0,mp);

    for(auto it : mp)
    {
        vector<int> v = it.second;
        for(auto i : v)
            cout<<i<<" ";
    }
    return 0;
}