/* Left View of a tree (https://practice.geeksforgeeks.org/problems/left-view-ofbinary-tree/1) */

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

vector<int> left_view(node* root)
{
    if(root == NULL)
    {
        return {};
    }
    vector<int> ans;
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        int n = q.size();
        bool flag = false;
        node* temp ;
        while(n--)
        {
            temp = q.front();
            q.pop();
            if(!flag)
            {
                ans.push_back(temp->data);
                flag = false;
            }
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
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
    node* root = new node(5);
    root->left = new node(3);
    root->right = new node(6);
    root->left->left = new node(2);
    root->left->right = new node(4);

    cout<<"\nPostorder traversal of tree  : ";
    postorder_traversal(root);

    vector<int> ans = left_view(root);
    cout<<"\nleft view of tree : ";
    for(auto i : ans)
        cout<<i<<" ";
    
    return 0;
}