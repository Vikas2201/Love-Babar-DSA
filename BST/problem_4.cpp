/* Find inorder successor and inorder predecessor in a BST
(https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1) */

#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
        int val;
        node *left , *right;

        node(int value)
        {
            val = value;
            left = NULL;
            right = NULL;
        }
};

void inorder(node* root,vector<int>& arr)
{
    if(root == NULL)
        return;
    inorder(root->left,arr);
    arr.push_back(root->val);
    inorder(root->right,arr);
}

void pre_suc_of_a_node(node* root,node*& pre,node*& suc,int value)
{
    if(root == NULL)
        return;
    vector<int> arr;
    inorder(root,arr);
    for(int i=0;i<arr.size();i++)
    {
        node* temp = new node(arr[i]);
        if(temp->val < value)
            pre = temp;
        if(temp->val > value)
        {
            suc = temp;
            break;
        }
    }
}

int main()
{
    node* root = new node(100);
    root->left = new node(20);
    root->right = new node(200);
    root->left->left = new node(10);
    root->left->right = new node(30);
    root->left->left->right = new node(40);

    node* pre = NULL;
    node* suc = new node(-1);
    int value;
    cout<<"Enter value for finding inorder successor and inorder predecessor : ";
    cin>>value;

    pre_suc_of_a_node(root,pre,suc,value);
    cout<<"\nInorder Predecessor : "<<pre->val;
    cout<<"\nInorder Successor : "<<suc->val;
    
    return 0;
}
