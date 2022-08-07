/* Convert Binary tree into BST (https://practice.geeksforgeeks.org/problems/binarytree-to-bst/1) */

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
    arr.push_back(root->data);
    traversal(root->left,arr);
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

node* Construct_BST_From_Tree(node* root)
{
    if(root == NULL)
        return NULL;

    vector<int> arr;
    traversal(root,arr);
    sort(arr.begin(),arr.end());

    return solve(arr,0,arr.size()-1);
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
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout<<"Inorder traversal of Tree : ";
    inorder_traversal(root);

    node* BST_root = Construct_BST_From_Tree(root);
    cout<<"\nInorder traversal of BST : ";
    inorder_traversal(BST_root);

    return 0;
}