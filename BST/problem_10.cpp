/* Convert a normal BST into a Balanced BST
(https://www.geeksforgeeks.org/convert-normal-bst-balanced-bst/) */

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

void traversal(node* root,vector<int>& arr)
{
    if(root == NULL)
        return ;
    traversal(root->left,arr);
    arr.push_back(root->data);
    traversal(root->right,arr);
}

node* solve(vector<int> arr,int start,int end)
{
    if(start > end)
        return NULL;
    int mid = start + (end - start)/2;
    node* root = new node(arr[mid]);
    root->left = solve(arr,start,mid-1);
    root->right = solve(arr,mid+1,end);

    return root;
}

node* Construct_Balance_Tree(node* root)
{
    if(root == NULL)
        return NULL;

    vector<int> arr;
    traversal(root,arr);

    return solve(arr,0,arr.size()-1);
}

void preorder(node* root)
{
    if(root == NULL)
        return ;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    node* root = new node(4);
    root->left = new node(3);
    root->left->left = new node(2);
    root->left->left->left = new node(1);
    root->right = new node(5);
    root->right->right = new node(6);
    root->right->right->right = new node(7);

    cout<<"\npreorder traversal of Tree : ";
    preorder(root);

    node* balance_root = Construct_Balance_Tree(root);
    cout<<"\npreorder traversal of Balance Tree : ";
    preorder(balance_root);

    return 0;
}