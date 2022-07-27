/* Find minimum swaps required to convert a Binary tree into BST
(https://www.geeksforgeeks.org/minimum-swap-required-convert-binary-treebinary-search-tree/) */

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

vector<int> inorder_array;
void inorder_traversal(node* root)
{
    if(root == NULL)
        return;
    inorder_traversal(root->left);
    inorder_array.push_back(root->data);
    inorder_traversal(root->right);
}

int minimum_swap()
{
    vector<pair<int,int>> p;
    int ans = 0;

    for(int i=0;i<inorder_array.size();i++)
        p.push_back({inorder_array[i],i});

    sort(p.begin(),p.end());
    
    for(int i=0;i<inorder_array.size();i++)
    {
        if(i == p[i].second)
            continue;
        
        else
        {
            swap(p[i].first,p[p[i].second].first);
            swap(p[i].second,p[p[i].second].second);
        }

        if(i != p[i].second)
            --i;

        ans++;       
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

    inorder_array.clear();
    cout<<"\ninorder traversal of tree  : ";
    inorder_traversal(root);

    for(auto v : inorder_array)
        cout<<v<<" ";

    
    cout<<"\nMinimum swap needed to convert biary tree into BST : "<<minimum_swap();
    
    return 0;
}