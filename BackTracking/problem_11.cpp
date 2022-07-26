/* Find shortest safe route in a path with landmines
(https://www.geeksforgeeks.org/find-shortest-safe-route-in-a-path-withlandmines/) */

#include<bits/stdc++.h>
using namespace std;

int solve(int n , int m , set<pair<int,int>>& st,vector<vector<bool>> visited,int i,int j,int c)
{
    if( i< 0 || j < 0 || i == n || j == m || st.count({i,j}) || visited[i][j])
        return INT_MAX;
    
    if(j == m-1)
        return c;

    visited[i][j] = true;
    int l1 = solve(n,m,st,visited,i+1,j,c+1);
    int l2 = solve(n,m,st,visited,i-1,j,c+1);
    int l3 = solve(n,m,st,visited,i,j+1,c+1);
    int l4 = solve(n,m,st,visited,i,j-1,c+1);
    
    visited[i][j] = false;
    return min({l1,l2,l3,l4});
} 

int main()
{
    int n , m ;
    cout<<"Enter row and column : ";
    cin>>n>>m;

    // vector<vector<int>> area(n, vector<int> (m,0));
    
    vector<vector<bool>> visited(n , vector<bool> (m,false));

    /* cout<<"Enter matrix with landmines : ";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>area[i][j];
        }
    } */

    vector<vector<int>> area =
    {
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }
    };

    // unsafe place
    set<pair<int,int>> st;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(area[i][j] == 0)
            {
                st.insert({i,j});

                if(i+1 < n)
                    st.insert({i+1,j});
                
                if(j+1 < m)
                    st.insert({i,j+1});

                if(i-1 >= 0)
                    st.insert({i-1,j});

                if(j-1 >= 0)
                    st.insert({i,j-1});
            }
        }
    }

    int ans = INT_MAX;
    for(int i=0;i<n;i++) //starting row place
    {
        if(st.count({i,0}) == 0)
        {
            int length = solve(12,10,st,visited,i,0,0);
            ans = min(ans,length);
        }
    }

    cout<<"Minimum length path for travelling in area with landmines : "<<ans;
    return 0;
}