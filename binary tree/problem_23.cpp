/* Check if all leaf nodes are at same level or not
(https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1) */

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

bool check(node* root)
{
    if(root == NULL)
        return true;

    queue<pair<node*,int>> q;
    q.push({root,0});
    vector<int> ans;
        
    while(!q.empty())
    {
        node* temp = q.front().first;
        int level = q.front().second;
        q.pop();
            
        if(temp->left == NULL && temp->right == NULL)
        {
            ans.push_back(level);
        }
        if(temp->left)
            q.push({temp->left,level+1});
        if(temp->right)
            q.push({temp->right,level+1});
    }
        
    int i;
    for(i=0;i<ans.size()-1;i++)
    {
        if(ans[i] != ans[i+1])
            return false;
    }
    if(i == (ans.size()-1))
        return true;   
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);

    cout<<check(root)<<" ";
    return 0;
}