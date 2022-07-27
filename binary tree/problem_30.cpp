/* Maximum Sum of nodes in Binary tree such that no two are adjacent
(https://www.geeksforgeeks.org/maximum-sum-nodes-binary-tree-no-twoadjacent/) */

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

vector<int> adjacent_sum(node* root)
{
    if(root == NULL)
        return {0,0};
    
    vector<int> a , b;
    a = adjacent_sum(root->left);
    b = adjacent_sum(root->right);

    vector<int> c(2);
    c[0] = a[1] + b[1] + root->data; // self node is include

    c[1] = max(a[0],b[1])+max(a[1],b[0]); // Either left or right child is included

    return c;
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

    vector<int> ans = adjacent_sum(root);
    cout<<"Maximum sum of subtree : "<<max(ans[0],ans[1]);
    return 0;
}