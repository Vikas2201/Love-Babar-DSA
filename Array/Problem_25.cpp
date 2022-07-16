/* Given an array of size n and a number k, find all elements that appear more than "n/k " times. 
        (https://leetcode.com/problems/majority-element-ii/) */

#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> arr,int k)
{
    unordered_map<int,int> mp;
    for(int i=0;i< arr.size() ;i++)
    {
        mp[arr[i]]++;
    }

    vector<int> ans;
    for(auto it : mp)
    {
        if(it.second > (arr.size()/k))
            ans.push_back(it.first);
    }
    return ans;
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

    int k = 0;
    cout<<"Enter the value of k : ";
    cin>>k;

    cout<<"All elements that appear more than ""n/k "" times in array : ";
    vector<int> ans = majorityElement(arr,k);

    for(auto i : ans)
        cout<<i<<" ";

    return 0;
}