/* Replace every element with the least greater element on its right
(https://www.geeksforgeeks.org/replace-every-element-with-the-least-greaterelement-on-its-right/) */

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

node* insert(node* root,int val,node* &succ)
{
    if(root == NULL)
        return root = new node(val);

    if(root->data > val)
    {
        succ = root;
        root->left = insert(root->left,val,succ);   
    }
    else if(root->data < val)
    {
        root->right = insert(root->right,val,succ);
    }
    return root;
}

void replace(vector<int>& arr,int n)
{
    node* root = NULL;
    for(int i=n-1 ; i>=0 ;i--)
    {
        node* succ = NULL;
        root = insert(root,arr[i],succ);

        if(succ)
        {
            arr[i] = succ->data;
        }
        else
            arr[i] = -1;
    }
}

int main()
{
    int n;
    cout<<"Enter size of arr : ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter value in arr : ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    replace(arr,n);
    cout<<"After Replace every element with the least greater element on its right then array will be : ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}