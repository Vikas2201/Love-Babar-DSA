/* Combinational Sum (https://practice.geeksforgeeks.org/problems/combinationsum/0) */

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> output;
void combinational_sum(vector<int>& arr,int i,int sum,vector<int>& ans)
{
    if(sum == 0)
    {
        output.push_back(ans);
        return;
    }
    if(sum < 0)
        return;
    
    while(i < arr.size() && sum - arr[i] >= 0)
    {
        ans.push_back(arr[i]);
        combinational_sum(arr,i,sum-arr[i],ans);
        i++;
        ans.pop_back();
    }
}

int main()
{
    int n;
    cout<<"Enter size of array : ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter element in array : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int sum;
    cout<<"Enter value of sum : ";
    cin>>sum;

    sort(arr.begin(), arr.end());
 
    // remove duplicates
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    vector<int> ans;
    combinational_sum(arr,0,sum,ans);

    cout<<"combinational subset : ";
    for(int i=0;i<output.size();i++)
    {
        for(int j=0;j<output[i].size();j++)
        {
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}