/* Find Kth smallest element in a BST
(https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-inbst/1) */

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

int ans = -1;

void solve(node* root,int k,int& i)
{
    if(root == NULL)
        return ;
    solve(root->left,k,i);
    i++;
    if(i == k)
    {
        ans = root->data;
        return ;
    }

    solve(root->right,k,i);
}

int kth_smallest_element(node* root,int k)
{
    if(root == NULL)
        return -1;
    int i = 0;
    solve(root,k,i);
    return ans;
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
    node* root = new node(100);
    root->left = new node(50);
    root->right = new node(300);
    root->left->left = new node(20);
    root->left->right = new node(70);

    cout<<"\nInorder traversal of tree : ";
    inorder_traversal(root);

    int k;
    cout<<"\nEnter value of k : ";
    cin>>k;

    cout<<"\n"<<k<<"th smallest element in tree : "<<kth_smallest_element(root,k);
    return 0;
}