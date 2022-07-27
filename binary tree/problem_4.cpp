/* Diameter of a tree (https://practice.geeksforgeeks.org/problems/diameter-ofbinary-tree/1) */

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

int cal_height(node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        int lheight = cal_height(root->left);
        int rheight = cal_height(root->right);

        return max(lheight , rheight) + 1;
    }
}

int diameter(node* root)
{
    if(root == NULL)
        return 0;
    
    int lh = cal_height(root->left);
    int rh = cal_height(root->right);

    int max_height = lh+rh+1;

    int ld = diameter(root->left);
    int rd = diameter(root->right);

    return max(max_height,max(ld,rd));
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

    int d = diameter(root);
    cout<<"\ndiameter of tree : "<<d;
    
    return 0;
}