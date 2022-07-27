/* Sum of Nodes on the Longest path from root to leaf node
(https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-ofa-tree/1) */

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

vector<int> solve(node* root)
{
    if(root == NULL)
        return {0,0};
    vector<int> a,b;
    a = solve(root->left);
    b = solve(root->right);

    if(a[0] > b[0])
        return {a[0]+1,a[1]+root->data};
    else if(a[0] < b[0])
        return {b[0]+1,b[1]+root->data};
    else
        return {a[0]+1,max(a[1],b[1])+root->data};
}


void longest_path_sum(node* root)
{
    if(root == NULL)
    {
        cout<<0<<" ";
        return;
    }
    vector<int> ans = solve(root);
    cout<<"Sum of longest path is : "<<ans[1];
    return;
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(2);
    root->right->left->left = new node(4);
    root->right->left->right = new node(5);

    longest_path_sum(root);
    return 0;
}