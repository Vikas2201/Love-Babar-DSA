/* Bottom View of a tree (https://practice.geeksforgeeks.org/problems/bottom-viewof-binary-tree/1) */

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

vector<int> bottom_view(node* root)
{
    if(root == NULL)
        return {};
    
    queue<pair<int,node*>> q;
    map<int,int> mp;
    q.push({0,root});
    while(!q.empty())
    {
        int dist = q.front().first;
        node* temp = q.front().second;
        q.pop();

        mp[dist] = temp->data;

        if(temp->left)
            q.push({dist-1,temp->left});
        if(temp->right)
            q.push({dist+1,temp->right});
    }

    vector<int> ans;
    for(auto it : mp)
    {
        ans.push_back(it.second);
    }

    return ans;
}

void postorder_traversal(node* root)
{
    if(root == NULL)
        return;
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout<<root->data<<" ";
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

    cout<<"\nPostorder traversal of tree  : ";
    postorder_traversal(root);

    vector<int> ans = bottom_view(root);
    cout<<"\nbottom view of tree : ";
    for(auto i : ans)
        cout<<i<<" ";
    
    return 0;
}