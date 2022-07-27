/* Find distance between 2 nodes in a Binary tree
(https://practice.geeksforgeeks.org/problems/min-distance-between-two-givennodes-of-a-binary-tree/1) */

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

node* LCA(node* root,int p,int q)
{
    if(root == NULL || root->data == p || root->data == q)
        return root;
    
    node* left = LCA(root->left,p,q);
    node* right = LCA(root->right,p,q);

    if(left == NULL)
        return right;
    else if(right == NULL)
        return left;
    else
        return root;
}

int solve(node* root,int x)
{
    if(root == NULL)
        return 0;
    if(root->data == x)
        return 1;
    int a = solve(root->left,x);
    int b = solve(root->right,x);
    if(!a && !b)
        return 0;
    else
        return a+b+1;
}

int min_distance(node* root,int a,int b)
{
    if(root == NULL)
        return 0;
    node* lca_node = LCA(root,a,b);
    int lh = solve(lca_node,a);
    int rh = solve(lca_node,b);

    return lh+rh-2;
}

int main()
{
    node* root = new node(1);
    root->left = new node(3);
    root->left->left = new node(2);
    root->left->right = new node(1);
    root->left->right->left = new node(1);
    root->right = new node(-1);
    root->right->left = new node(4);
    root->right->left->left = new node(1);
    root->right->left->right = new node(2);
    root->right->right = new node(5);
    root->right->right->right = new node(2);


    int ans = min_distance(root,3,5);
    cout<<"minimum distance between 3 and 5 : "<<ans;
  
    return 0;
}
