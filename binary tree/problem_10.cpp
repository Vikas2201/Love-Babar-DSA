/* Right View of Tree (https://practice.geeksforgeeks.org/problems/right-view-ofbinary-tree/1) */

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

vector<int> right_view(node* root)
{
    if(root == NULL)
        return {};
    
    vector<int> ans;
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        int n = q.size();
        bool flag = false;

        while(n--)
        {
            node* temp = q.front();
            q.pop();
            if(!flag)
            {
                ans.push_back(temp->data);
                flag = true;
            }
            if(temp->right)
                q.push(temp->right);
            if(temp->left)
                q.push(temp->left);
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

    vector<int> ans = right_view(root);
    cout<<"\nright view of tree : ";
    for(auto i : ans)
        cout<<i<<" ";
    
    return 0;
}

