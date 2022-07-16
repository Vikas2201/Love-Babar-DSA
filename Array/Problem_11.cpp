/* find duplicate in an array of N+1 Integers (https://leetcode.com/problems/find-theduplicate-number/) */

#include<bits/stdc++.h>
using namespace std;

int duplicated(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n,0);
    for(int i=0;i<n;i++)
    {
        ans[arr[i]]+=1;
        if(ans[arr[i]] == 2)
        {
            return arr[i];
        }
    }
    return 0;
}

int main()
{
    int n;
    cout<<"Enter size of arr : ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter element in arr in the range of [1 ,"<<n-1<<" ] : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int dupliate_num = duplicated(arr);
    cout<<"Duplicate number in an array : "<<dupliate_num;
    
    return 0;
}