/* Find all Duplicate subtrees in a Binary tree [ IMP ]
(https://practice.geeksforgeeks.org/problems/duplicate-subtrees/1) */

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

unordered_map<string,int> mp;
string solve(node* root,vector<int>& ans)
{
    if(root == NULL)
        return "$";
    
    string s = "";
    s += to_string(root->data);
    s += solve(root->left,ans);
    s += solve(root->right,ans);

    if(mp[s] == 1)
    {
        ans.push_back(root->data);
    }
    mp[s]++;
    return s;
}

void duplicates(node* root)
{
    mp.clear();
    vector<int> ans;
    string s = solve(root,ans);
    if(ans.size() > 0)
    {
        cout<<"roots of duplicates subtree in a tree : ";
        for(auto x: ans)
            cout<<x<<" ";
    }
    else
        cout<<"there is no duplicates subtree in a tree";
    return ;
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

    duplicates(root);
    return 0;
}

