/* The Knight’s tour problem (https://www.geeksforgeeks.org/the-knights-tourproblem-backtracking-1/) */

#include<bits/stdc++.h>
using namespace std;

void solve(int i,int j, int n,vector<vector<bool>>& visited,vector<vector<int>>& ans ,int c)
{
    if(i < 0 || j < 0 || i >= n || j >= n)
    {
        return;
    }
    if(visited[i][j])
        return ;
    if(c == (n*n-1))
    {
        ans[i][j] = c;
        return;
    }
    visited[i][j] = true;

    ans[i][j] = c;
    solve(i-2,j+1,n,visited,ans,c+1);
    solve(i-2,j-1,n,visited,ans,c+1);
    solve(i+2,j+1,n,visited,ans,c+1);
    solve(i+2,j-1,n,visited,ans,c+1);
    solve(i-1,j+2,n,visited,ans,c+1);
    solve(i-1,j-2,n,visited,ans,c+1);
    solve(i+1,j+2,n,visited,ans,c+1);
    solve(i+1,j-2,n,visited,ans,c+1);

    visited[i][j] = false;
    ans[i][j] = 0;

    return ;
}

int main()
{
    int n;
    cout<<"Enter size of board : ";
    cin>>n;

    vector<vector<bool>> visited(n, vector<bool> (n,false));
    vector<vector<int>> ans(n, vector<int> (n,0));

    solve(0,0,n,visited,ans,0);

    cout<<"Path travelled by knight : ";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}