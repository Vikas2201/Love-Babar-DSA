/* Preorder Traversal of a tree both using recursion and Iteration
(https://www.techiedelight.com/preorder-tree-traversal-iterative-recursive/) */

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

void preorder_traversal_recursion(node* root)
{
    if(root == NULL)
        return ;
    cout<<root->data<<" ";
    preorder_traversal_recursion(root->left);
    preorder_traversal_recursion(root->right);
}

void preorder_traversal_iteration(node* root)
{
    stack<node*> st;
    st.push(root);
    while(!st.empty())
    {
        node* temp = st.top();
        st.pop();
        cout<<temp->data<<" ";
        if(temp->right != NULL)
            st.push(temp->right);

        if(temp->left != NULL)
            st.push(temp->left);
    }
}

int main()
{
    node* root = new node(5);
    root->left = new node(3);
    root->right = new node(6);
    root->left->left = new node(2);
    root->left->right = new node(4);

    cout<<"\nPreorder traversal of tree using recursion : ";
    preorder_traversal_recursion(root);

    cout<<"\nPreorder traversal of tree using iteration : ";
    preorder_traversal_iteration(root);
    
    return 0;
}