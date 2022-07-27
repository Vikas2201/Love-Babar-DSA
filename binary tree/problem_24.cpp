/* Check if a Binary Tree contains duplicate subtrees of size 2 or more [ IMP ]
(https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1) */

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

unordered_map<string,int> mp;

string check(node* root)
{
    if(root == NULL)
    {
        return "$";
    }
    string s = "";
    if(root->left == NULL && root->right == NULL)
    {
        s += to_string(root->data);
        return s;
    }
    s += to_string(root->data);
    s += check(root->left);
    s += check(root->right);
        
    mp[s]++;
    return s;
}

bool dupSub(node *root) 
{
    mp.clear();
    check(root);
    for(auto x : mp)
    {
        if(x.second >= 2)
            return true;
    }
    return false;
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

    cout<<"Check two same subtree exist or not : "<<dupSub(root);
    return 0;
}