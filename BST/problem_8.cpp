/* Construct BST from preorder traversal (https://www.geeksforgeeks.org/constructbst-from-given-preorder-traversa/) */

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

node* construct_BST(vector<int> preorder,int& pos,int min,int max)
{
    if(pos >= preorder.size())
        return NULL;
    
    node* root = NULL;
    if(preorder[pos] > min && preorder[pos] < max)
    {
        int val = preorder[pos];
        root = new node(val);
        pos++;

        if(pos < preorder.size())
        {
            root->left = construct_BST(preorder,pos,min,val);
        }
        if(pos < preorder.size())
        {
            root->right = construct_BST(preorder,pos,val,max);
        }
    }
    return root;
}

void preorder_traversal(node* root)
{
    if(root== NULL)
        return ;
    cout<<root->data<<" ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

int main()
{
    int n;
    cout<<"Enter no. of nodes : ";
    cin>>n;

    vector<int> preorder(n);
    cout<<"Enter preorder traversal of BST Tree : ";
    for(int i=0;i<n;i++)
        cin>>preorder[i];
    int pos = 0;
    node* root = construct_BST(preorder,pos,INT_MIN,INT_MAX);
    cout<<"After constructing BST preorder traversal : ";
    preorder_traversal(root);

    return 0;
}