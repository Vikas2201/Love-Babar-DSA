/* Find Largest subtree sum in a tree (https://www.geeksforgeeks.org/find-largestsubtree-sum-tree/) */

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

int ans = INT_MIN;
int sum(node* root)
{
    if(root == NULL)
        return 0;
    int lh = sum(root->left);
    int rh = sum(root->right);

    ans = max(ans,lh+rh+root->data);
    return lh+rh+root->data;
}

int main()
{
    node* root = new node(1);
    root->left = new node(-2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(-6);
    root->right->right = new node(2);

    sum(root);
    cout<<"Maximum sum of subtree : "<<ans;
    return 0;
}