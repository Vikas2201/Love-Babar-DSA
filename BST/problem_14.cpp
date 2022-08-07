/*  Count pairs from 2 BST whose sum is equal to given value "X"
(https://practice.geeksforgeeks.org/problems/brothers-from-different-root/1) */

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

void dfs(node* root,map<int,int>& mp)
{
    if(root == NULL)
        return ;
    dfs(root->left,mp);
    mp[root->data]++;
    dfs(root->right,mp);
}

int ans = 0;
void getpair(node* root,map<int,int>& mp,int sum)
{
    if(root == NULL)
        return ;
    if(mp.count(sum - root->data) >= 1)
        ans++;

    getpair(root->left,mp,sum);
    getpair(root->right,mp,sum);
}

int sum_of_pair(node* root1,node* root2,int sum)
{
    map<int,int> mp;
    dfs(root1,mp);

    getpair(root2,mp,sum);
    return ans;
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

    int sum;
    cout<<"Enter value of sum : ";
    cin>>sum;

    int count = sum_of_pair(root1, root2,sum);
 
    cout << "Count of Sum Pairs in 2 BST : "<<count;
 
    return 0;
}