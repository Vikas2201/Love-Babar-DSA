/* Height of a tree (https://practice.geeksforgeeks.org/problems/height-of-binarytree/1) */

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

int height_of_tree(node* root)
{
    if(root == NULL)
        return 0;
    int lh = height_of_tree(root->left);
    int rh = height_of_tree(root->right);

    return max(lh,rh) + 1;
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

    int h = height_of_tree(root);
    cout<<"\nHeight of tree : "<<h;
    
    return 0;
}