/* Rat in a maze Problem (https://practice.geeksforgeeks.org/problems/rat-in-amaze-problem/1) */

#include<bits/stdc++.h>
using namespace std;

string ans = "";
vector<string> output;
map<int,char> mp = {{1,'L'},{2,'R'},{3,'U'},{4,'D'}};
void maze_problem(vector<vector<int>>& arr,int i , int j,vector<vector<int>>& visited,string ans,int move = 0)
{
    if(i < 0 || j < 0 || i >= arr.size() || j >= arr.size())
        return ;
    if(arr[i][j] == 0 || visited[i][j] == 1)
        return ;
    
    if(move != 0)
        ans += mp[move];
    if(i == arr.size()-1 && j == arr.size()-1)
        output.push_back(ans);
    
    visited[i][j] = 1;
    maze_problem(arr,i+1,j,visited,ans,4);
    maze_problem(arr,i-1,j,visited,ans,3);
    maze_problem(arr,i,j+1,visited,ans,2);
    maze_problem(arr,i,j-1,visited,ans,1);

    visited[i][j] = 0;
}

int main()
{
    int n;
    cout<<"Enter size of maze : ";
    cin>>n;

    vector<vector<int>> arr(n , vector<int> (n,0));
    cout<<"Enter maze : "; 
    for(int i=0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }

    vector<vector<int>> visited(n,vector<int> (n,0));
    maze_problem(arr,0,0,visited,ans);

    cout<<"Path to reached end point in maze : ";
    for(auto i : output)
    {
        cout<<i<<" ";
    }

    return 0;
}