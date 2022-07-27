/* Find LCA in a Binary tree (https://practice.geeksforgeeks.org/problems/lowestcommon-ancestor-in-a-binary-tree/1) */

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

node* LCA(node* root,int p,int q)
{
    if(root == NULL || root->data == p || root->data == q)
        return root;
    
    node* left = LCA(root->left,p,q);
    node* right = LCA(root->right,p,q);

    if(left == NULL)
        return right;
    else if(right == NULL)
        return left;
    else
        return root;
}

int main()
{
    node* root = new node(1);
    root->left = new node(3);
    root->left->left = new node(2);
    root->left->right = new node(1);
    root->left->right->left = new node(1);
    root->right = new node(-1);
    root->right->left = new node(4);
    root->right->left->left = new node(1);
    root->right->left->right = new node(2);
    root->right->right = new node(5);
    root->right->right->right = new node(2);


    node* ans = LCA(root,3,5);
    cout<<"LCA OF 3 and 5 : "<<ans->data;
  
    return 0;
}