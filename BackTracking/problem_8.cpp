/* Subset Sum Problem (https://practice.geeksforgeeks.org/problems/subset-sumproblem2014/1) */

#include<bits/stdc++.h>
using namespace std;

bool issubset(int arr[],int i,int n,int sum,vector<vector<int>>& dp)
{
    if(i == n)
    {
        if(sum == 0)
            return true;
        else
            return false;
    }
    if(dp[i][sum] != -1)
        return dp[i][sum];
    return dp[i][sum] = issubset(arr,i+1,n,sum,dp) or issubset(arr,i+1,n,sum-arr[i],dp);
}
    
void equalPartition(int n, int arr[])
{
    int sum = 0;
    for(int i=0;i<n;i++)
        sum += arr[i];
        
    if(sum%2 == 1)
    {
        cout<<"Partation of array is not possible";
        return ;
    }
            
    vector<vector<int>> dp(n,vector<int>(sum,-1));
    if(issubset(arr,0,n,sum/2,dp))
    {
        cout<<"Partation of array is possible";
        return ;
    }
    else
    {
        cout<<"Partation of array is not possible";
        return ;
    }
}

int main()
{
    int n;
    cout<<"Enter size of array : ";
    cin>>n;

    int arr[n];
    cout<<"Enter elements in array : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    equalPartition(n,arr);
    return 0;
}