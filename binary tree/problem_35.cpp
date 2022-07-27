/* Tree Isomorphism Problem (https://practice.geeksforgeeks.org/problems/checkif-tree-is-isomorphic/1) */

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

bool isIsomorphic(node *root1,node *root2)
{
    if(!root1 && !root2)
        return true;
    if(!root1 || !root2)
        return false;
    if(root1->data!=root2->data)
        return false;
    bool a=isIsomorphic(root1->left,root2->left) && isIsomorphic(root1->right,root2->right);
    bool b=isIsomorphic(root1->left,root2->right) && isIsomorphic(root1->right,root2->left);
    return a||b;
}

