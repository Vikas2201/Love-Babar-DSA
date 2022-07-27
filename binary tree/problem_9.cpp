/* Postorder Traversal of a tree both using recursion and Iteration
(https://www.techiedelight.com/postorder-tree-traversal-iterative-recursive/) */

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

void postorder_traversal_recursion(node* root)
{
    if(root == NULL)
        return;
    postorder_traversal_recursion(root->left);
    postorder_traversal_recursion(root->right);
    cout<<root->data<<" ";
}

void postorder_traversal_iteration(node* root)
{
    if(root == NULL)
        return ;
    stack<node*> st;
    st.push(root);

    stack<int> ans;
    while(!st.empty())
    {
        node* temp = st.top();
        st.pop();

        ans.push(temp->data);
        if(temp->left)
            st.push(temp->left);
        
        if(temp->right)
            st.push(temp->right);
    }

    while(!ans.empty())
    {
        cout<<ans.top()<<" ";
        ans.pop();
    }
}

int main()
{
    node* root = new node(5);
    root->left = new node(3);
    root->right = new node(6);
    root->left->left = new node(2);
    root->left->right = new node(4);

    cout<<"\nPostorder traversal of tree using recursion : ";
    postorder_traversal_recursion(root);

    cout<<"\nPostorder traversal of tree using iteration : ";
    postorder_traversal_iteration(root);
    
    return 0;
}