/* Reverse Level Order traversal
(https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1) */

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

vector<int> res;

void help(queue<node*> &q)
{
    if(q.empty())
        return;
    node* a = q.front();
    q.pop();
    if(a->left)
        q.push(a->left);
    if(a->right)
        q.push(a->right);
    help(q);
    res.push_back(a->data);
}

vector<int> reverse_level_order_traversal(node* root)
{
    if(root == NULL)
        return {};
    queue<node*> q;
    q.push(root);
    help(q);
    return res;
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

    vector<int> ans = reverse_level_order_traversal(root);
    cout<<"\nReverse Level Order Traversal : ";
    for(auto i : ans)
        cout<<i<<" ";
    return 0;
}