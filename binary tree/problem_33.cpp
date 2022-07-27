/* Kth Ancestor of node in a Binary tree (https://www.geeksforgeeks.org/kthancestor-node-binary-tree-set-2/) */

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

node* kth_ancestor(node* root,int val,int &k)
{
    if(root == NULL)
        return root;
    if(root->data == val || kth_ancestor(root->left,val,k) || kth_ancestor(root->right,val,k))
    {
        if(k > 0)
            k--;
        else if(k == 0)
        {
            cout<<root->data<<" ";
            return NULL;
        }
        return root;
    }
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    int k = 2;
    cout<<"2nd ancestor of node 5 : ";
    node* ans = kth_ancestor(root,5,k);
    if(ans)
        cout<<-1<<" ";

    return 0;
}
