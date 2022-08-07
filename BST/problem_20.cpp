/* Check whether BST contains Dead end
(https://practice.geeksforgeeks.org/problems/check-whether-bst-containsdead-end/1) */

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

void traversal(node* root,unordered_set<int>& st)
{
    if(root == NULL)
        return ;
    traversal(root->left,st);
    st.insert(root->data);
    traversal(root->right,st);
}

bool check_dead_end(node* root,unordered_set<int> st)
{
    if(root == NULL)
        return false;
    if(root->left == NULL && root->right == NULL)
    {
        if(st.count(root->data - 1) && st.count(root->data + 1))
            return true;
    }
    return check_dead_end(root->left,st) || check_dead_end(root->right,st);
}

bool is_dead_end(node* root)
{
    unordered_set<int> st;
    st.insert(0);

    traversal(root,st);
    return check_dead_end(root,st);
}

int main()
{
    node* root = new node(8);
    root->left = new node(7);
    root->right = new node(10);
    root->left->left = new node(2);
    root->right->left = new node(9);
    root->right->right = new node(13);

    cout<<"Check whather BST have Dead End or not : "<<is_dead_end(root);

    return 0;
}