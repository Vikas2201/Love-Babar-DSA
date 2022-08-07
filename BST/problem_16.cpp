/* Count BST ndoes that lie in a given range
(https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-agiven-range/1) */

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

void range(node* root,int l,int r,vector<int>& arr)
{
    if(root == NULL)
        return ;

    range(root->left,l,r,arr);
    if(root->data >= l && root->data <= r)
        arr.push_back(root->data);
    range(root->right,l,r,arr);
}

void inorder_traversal(node* root)
{
    if(root == NULL)
        return ;
    inorder_traversal(root->left);
    cout<<root->data<<" ";
    inorder_traversal(root->right);
}

int main()
{
    /* Create following tree as first balanced BST
        100
        / \
        50 300
        / \
        20 70
    */
    node* root = new node(10);
    root->left = new node(5);
    root->right = new node(50);
    root->left->left = new node(1);
    root->left->right = new node(7);
    root->right->left = new node(40);
    root->right->right = new node(100);

    cout<<"\nInorder traversal of tree : ";
    inorder_traversal(root);

    vector<int> arr;
    int l , r;
    cout<<"\nEnter range : ";
    cin>>l>>r;

    range(root,l,r,arr);
    cout<<"\nValue of node in given range : ";
    for(auto i: arr)
        cout<<i<<" ";

    return 0;
}