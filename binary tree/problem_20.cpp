/* Construct Binary tree from Inorder and preorder traversal
(https://practice.geeksforgeeks.org/problems/construct-tree-1/1) */

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

unordered_map<int,int> mp;

node* make_tree(vector<int>& preorder,int start ,int partition, int end)
{
    if(end - partition < 0)
        return NULL;
    
    auto root = new node(preorder[start]);
    int p = mp[preorder[start]];

    root->left = make_tree(preorder,start+1,partition,p-1);
    root->right = make_tree(preorder,start+p-partition+1,p+1,end);

    return root;
}

node* buildTree(vector<int>& preorder, vector<int>& inorder) 
{
    for(int i=0;i<inorder.size();i++)
    {
        mp[inorder[i]] = i;
    }
    return make_tree(preorder,0,0,inorder.size()-1);
}

void preorder_traversal(node* root)
{
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

int main()
{
    int n;
    cout<<"Enter no. of nodes : ";
    cin>>n;

    vector<int> preorder(n) , inorder(n);
    cout<<"Enter preorder traversal of a tree : ";
    for(int i=0;i<n;i++)
    {
        cin>>preorder[i];
    }

    cout<<"Enter inorder traversal of a tree : ";
    for(int i=0;i<n;i++)
    {
        cin>>inorder[i];
    }

    node* root = buildTree(preorder,inorder);
    cout<<"\nAfter buliding tree preorder traversal is : ";
    preorder_traversal(root);
    
    return 0;
}