/* Check preorder is valid or not
(https://practice.geeksforgeeks.org/problems/preorder-to-postorder/0) */

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

node* insert(node* root,int val)
{
    if(root == NULL)
        return root = new node(val);

    if(root->data > val)
    {
        root->left = insert(root->left,val);
    }
    else
        root->right = insert(root->right,val);
    return root;
}

node* BST_From_Preorder(vector<int> preorder)
{
    node* root = new node(preorder[0]);
    for(int i=1;i<preorder.size();i++)
    {
        insert(root,preorder[i]);
    }
    return root;
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
    int n;
    cout<<"No. of node in BST : ";
    cin>>n;

    vector<int> preorder(n);
    cout<<"Enter preorder traversal of BST : ";
    for(int i=0;i<n;i++)
        cin>>preorder[i];

    node* root = BST_From_Preorder(preorder);
    cout<<"Inorder traversal of BST : ";
    inorder_traversal(root);

    return 0;
}