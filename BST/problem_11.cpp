/* Merge two BST [ V.V.V>IMP ] (https://www.geeksforgeeks.org/merge-twobalanced-binary-search-trees/) */

#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
        int data;
        node *left , *right;

        node(int val)
        {
            data = val;
            left = NULL;
            right = NULL;
        }
};

void traversal(node* root,vector<int>& arr)
{
    if(root == NULL)
        return ;
    traversal(root->left,arr);
    arr.push_back(root->data);
    traversal(root->right,arr);
}

vector<int> merge(vector<int> arr1,vector<int> arr2)
{
    int n = arr1.size() , m = arr2.size();
    int i=0, j =0 , k =0;
    vector<int> arr(n+m,0);
    while(i < n && j < m)
    {
        if(arr1[i] < arr2[j])
        {
            arr[k] = arr1[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
            k++;
        }
    }
    while(i < n)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while(j < m)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }
    return arr;
}

node* solve(vector<int> arr,int start,int end)
{
    if(start > end)
        return NULL;
    int mid = start + (end - start)/2;
    node* root = new node(arr[mid]);
    root->left = solve(arr,start,mid-1);
    root->right = solve(arr,mid+1,end);

    return root;
}

node* Merge_BST(node* root1,node* root2)
{
    if(root1 == NULL)
        return root2;
    if(root2 == NULL)
        return root1;
    
    vector<int> arr1 , arr2;
    traversal(root1,arr1);

    traversal(root2,arr2);

    vector<int> arr = merge(arr1,arr2);
    
    int start = 0 , end = arr.size()-1;
    return solve(arr,start,end);
}

void inorder_traversal(node* root)
{
    if(root == NULL)
        return ;
    inorder_traversal(root->left);
    cout<<root->data<<" ";
    inorder_traversal(root->right);
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
    node* root1 = new node(100);
    root1->left = new node(50);
    root1->right = new node(300);
    root1->left->left = new node(20);
    root1->left->right = new node(70);
 
    /* Create following tree as second balanced BST
        80
        / \
        40 120
    */
    node* root2 = new node(80);
    root2->left = new node(40);
    root2->right = new node(120);
 
    node* mergedTree = Merge_BST(root1, root2);
 
    cout << "Inorder traversal of the merged tree \n";
    inorder_traversal(mergedTree);
 
    return 0;
}
 