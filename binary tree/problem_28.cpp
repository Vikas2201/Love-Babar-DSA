/* Print all "K" Sum paths in a Binary tree (https://www.geeksforgeeks.org/print-ksum-paths-binary-tree/) */

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

void print_path(vector<int>& path, int i)
{
    for (int j = i; j < path.size(); j++)
        cout<<path[j]<<" ";
    cout << endl;
}

void print_k_sum_path(node* root,vector<int>& path,int k)
{
    if(root == NULL)
        return;
    
    path.push_back(root->data);

    print_k_sum_path(root->left,path,k);
    print_k_sum_path(root->right,path,k);

    int sum = 0;
    for(int i=path.size()-1;i>=0;i--)
    {
        sum += path[i];
        if(sum == k)
        {
            print_path(path,i);
        }
    }
    path.pop_back();
}

int main()
{
    node* root = new node(1);
    root->left = new node(3);
    root->left->left = new node(2);
    root->left->right = new node(1);
    root->left->right->left = new node(1);
    root->right = new node(-1);
    root->right->left = new node(4);
    root->right->left->left = new node(1);
    root->right->left->right = new node(2);
    root->right->right = new node(5);
    root->right->right->right = new node(2);
    
    int k;
    cout<<"Enter the value of k : ";
    cin>>k;
    cout<<"Paths : \n";
    vector<int> path;
    print_k_sum_path(root,path,k);
  
    return 0;
}