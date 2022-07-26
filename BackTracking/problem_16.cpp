/* Longest Possible Route in a Matrix with Hurdles
(https://www.geeksforgeeks.org/longest-possible-route-in-a-matrix-withhurdles/) */

#include<bits/stdc++.h>
using namespace std;

int Max = INT_MIN;
void longest_path(vector<vector<int>>& arr,int n ,int m,int i , int j,int c,vector<vector<bool>>& visited,int x,int y)
{
    if(i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || arr[i][j] == 0)
        return ;
    if(i == x && j == y)
    {
        Max = max(Max,c);
        return ;
    }
    visited[i][j] = true;

    longest_path(arr,n,m,i+1,j,c+1,visited,x,y);
    longest_path(arr,n,m,i,j+1,c+1,visited,x,y);
    longest_path(arr,n,m,i-1,j,c+1,visited,x,y);
    longest_path(arr,n,m,i,j-1,c+1,visited,x,y);

    visited[i][j] = false;
}

int main()
{
    vector<vector<int>> arr = { { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                      { 1, 1, 0, 1, 1, 0, 1, 1, 0, 1 },
                      { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };

    int n = arr.size() , m = arr[0].size();

    vector<vector<bool>> visited(n,vector<bool> (m,false));


    longest_path(arr,n,m,0,0,0,visited,1,7);
    cout<<"Longest path : "<<Max;

    return 0;
}