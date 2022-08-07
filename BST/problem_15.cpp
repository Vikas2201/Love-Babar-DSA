/* Find the median of BST in O(n) time and O(1) space
(https://www.geeksforgeeks.org/find-median-bst-time-o1-space/) */

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

void inorder(node* root,vector<int>& arr)
{
    if(root == NULL)
        return ;
    
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}

int median(node* root)
{
    if(root == NULL)
        return -1;
    
    vector<int> arr;
    inorder(root,arr);
    int n = arr.size();
    if(n%2 ==  0)
    {
        int pos = n/2;
        return (arr[pos] + arr[pos+1])/2;
    }
    else
    {
        int pos = (n+1)/2;
        return arr[pos];
    }
    return -1;
}

int main()
{
    /* Create following tree as first balanced BST
        100
        / \
        50 300
        / \
        20 70
    */
    node* root = new node(100);
    root->left = new node(50);
    root->right = new node(300);
    root->left->left = new node(20);
    root->left->right = new node(70);

    cout<<"Median value in BST : "<<median(root);
    return 0;
}