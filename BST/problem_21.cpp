/* Largest BST in a Binary Tree [ V.V.V.V.V IMP ]
(https://practice.geeksforgeeks.org/problems/largest-bst/1) */

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

