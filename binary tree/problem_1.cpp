/* level order traversal (https://practice.geeksforgeeks.org/problems/level-ordertraversal/1) */

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

vector<int> level_order_traversal(node* root)
{
    if(root == NULL)
        return {};
    queue<node*> q;
    q.push(root);
    vector<int> ans;
    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();
        ans.push_back(temp->data);
        if(temp->left != NULL)
            q.push(temp->left);
        if(temp->right != NULL)
            q.push(temp->right);
    }
    return ans;
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

    vector<int> ans = level_order_traversal(root);
    cout<<"\nLevel Order Traversal : ";
    for(auto i : ans)
        cout<<i<<" ";
    return 0;
}