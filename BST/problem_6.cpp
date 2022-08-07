/* Populate Inorder successor of all nodes
(https://practice.geeksforgeeks.org/problems/populate-inorder-successor-forall-nodes/1) */

#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
        int data;
        node *left , *right ,*next;

        node(int val)
        {
            data = val;
            left = NULL;
            right = NULL;
            next = NULL;
        }
};

void inorder(node* root,vector<node*>& arr)
{
    if(root == NULL)
        return ;
    inorder(root->left,arr);
    arr.push_back(root);
    inorder(root->right,arr);
}

void populateNext(node* root)
{
    if(root == NULL)
        return ;
    vector<node*> arr;
    inorder(root,arr);
    for(int i=0;i<arr.size()-1;i++)
    {
        arr[i]->next = arr[i+1];
    }
    arr[arr.size()-1]->next = new node(-1);
}

void print(node* root)
{
    if(root == NULL)
        return ;
    node* temp = root;
    while(temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
}

node* inorder_successor_root(node* root)
{
    if(root->left == NULL)
        return root;
    return inorder_successor_root(root->left);
}

int main()
{
    node* root = new node(10);
    root->left = new node(8);
    root->right = new node(12);
    root->left->left = new node(3);

    populateNext(root);
    node* pre_root = inorder_successor_root(root);
    cout<<"Populate Inorder successor of all nodes : ";
    print(pre_root);
}