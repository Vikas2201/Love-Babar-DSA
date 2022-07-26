/* Partition of a set intoK subsets with equal sum
(https://practice.geeksforgeeks.org/problems/partition-array-to-k-subsets/1) */

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> output;

void partition_sum(vector<int>& arr,vector<int>& ans,int k,int sum,int currsum,int pos,vector<bool> visited)
{
    if(k == 0)
    {
        output.push_back(ans);
        return ;
    }
    if(sum < currsum)
        return ;
    if(sum == currsum)
    {
        output.push_back(ans);
        partition_sum(arr,ans,k-1,sum,0,0,visited);
    }
    for(int i=pos;i<arr.size();i++)
    {
        if(visited[i])
            continue;
        visited[i] = true;
        ans.push_back(arr[i]);
        partition_sum(arr,ans,k,sum,currsum+arr[i],i+1,visited);
        ans.pop_back();
    }
}

int main()
{
    int n;
    cout<<"Enter size of array : ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter element of array : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int k;
    cout<<"Enter the value of k : ";
    cin>>k;

    int totalsum = 0;
    for(int i=0;i<n;i++)
        totalsum += arr[i];

    int sum = totalsum / k; 
    vector<int> ans;
    vector<bool> visited(n,false);
    partition_sum(arr,ans,k,sum,0,0,visited);

    cout<<"Output : ";
    for(int i = 0;i<output.size();i++)
    {
        for(int j=0;j<output[i].size();j++)
        {
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}