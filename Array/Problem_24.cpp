/* Find longest consecutive subsequence
(https://practice.geeksforgeeks.org/problems/longest-consecutivesubsequence/0) */

#include<bits/stdc++.h>
using namespace std;

int length_of_longest_subsequence(vector<int> arr)
{
    int count = 1 , mxcount = 0;
    sort(arr.begin(),arr.end());
    for(int i = 0;i<arr.size() - 1;i++)
    {
        if(arr[i+1] - arr[i] == 1)
            count++;
        else
            count = 1;
        mxcount = max(mxcount,count);
    }
    return mxcount;
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

    cout<<"Maximum length of longest consecutive subsequence : "<<length_of_longest_subsequence(arr);

    return 0;
}