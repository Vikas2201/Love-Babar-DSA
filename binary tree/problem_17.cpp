/* Construct Binary Tree from String with Bracket Representation
(https://www.geeksforgeeks.org/construct-binary-tree-string-bracketrepresentation/) */

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

int find_index(string str,int s,int e)
{
    if(s > e)
        return -1;
    
    stack<char> st;

    for(int i=s;i<= e;i++)
    {
        if(str[i] == '(')
            st.push('(');
        
        else if(str[i] == ')')
        {
            if(st.top() == '(')
            {
                st.pop();

                if(st.empty())
                    return i;
            }
        }
    }
    return -1;
}

node* bulid_tree_from_string(string str,int s,int e)
{
    if(s > e)
        return NULL;

    node* root = new node(str[s] - '0');
    int index = -1;

    if(s+1 <= e && str[s+1] == '(')
        index = find_index(str,s+1,e);

    if(index != -1)
    {
        root->left = bulid_tree_from_string(str,s+2,index-1);

        root->right = bulid_tree_from_string(str,index+2,e-1);
    }
    return root;
}

void postorder_traversal(node* root)
{
    if(root == NULL)
        return;
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout<<root->data<<" ";
}

int main()
{
    string str = "4(2(3)(1))(6(5))";
    node* root = bulid_tree_from_string(str, 0, str.length() - 1);
    cout<<"PreOrder traversal of tree : ";
    postorder_traversal(root);
}