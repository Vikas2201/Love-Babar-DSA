/* Find if there is any subarray with sum equal to 0
(https://practice.geeksforgeeks.org/problems/subarray-with-0-sum/0) */

#include<bits/stdc++.h>
using namespace std;

bool check_sum(vector<int> arr)
{
    unordered_map<int,int> mp;
    int sum = 0;
    for(int i=0;i<arr.size();i++)
    {
        sum += arr[i];
        if(sum == 0 || mp[sum] || arr[i] == 0)
            return true;
        mp[sum]++;
    }
    return false;
}

int main()
{
    int n;
    cout<<"Enter size of arr : ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter element in arr : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<"Is any subarray with sum equal to 0 : "<<check_sum(arr);

    return 0;
}
