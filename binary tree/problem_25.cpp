/* Check if 2 trees are mirror or not
(https://practice.geeksforgeeks.org/problems/check-mirror-in-n-ary-tree/0) */

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

bool check(node* root1,node* root2)
{
    if(root1 == NULL && root2 == NULL)
        return true;
    if((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL))
        return false;
    if(root1->data == root2-> data)
    {
        return check(root1->left,root2->right) && check(root1->right,root2->left);
    }
    return false;
}

int main()
{
    node* root1 = new node(1);
    root1->left = new node(2);
    root1->right = new node(3);
    
    node* root2 = new node(1);
    root2->left = new node(3);
    root2->right = new node(2);

    cout<<"Check if 2 trees are mirror or not : "<<check(root1,root2);
    return 0;
}
