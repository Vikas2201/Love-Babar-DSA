/* Minimum swaps required bring elements less equal K together
(https://practice.geeksforgeeks.org/problems/minimum-swaps-required-tobring-all-elements-less-than-or-equal-to-k-together/0) */

#include<bits/stdc++.h>
using namespace std;

int minimum_swaps(vector<int> arr , int k)
{
    int count = 0;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i] <= k)
            count++;
    }

    if(count == 0)
        return 0;
    
    int i = 0 , j = 0 , bad = 0;
    int ans = INT_MAX;

    while(i < arr.size())
    {
        if(arr[i] > k)
            bad++;
        if(i -j + 1 < count)
            i++;
        else if(i-j+1 == count)
        {
            ans = min(ans,bad);
            if(arr[j] > k)
                bad--;
            i++; 
            j++;
        }
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

    int k;
    cout<<"Enter the value of k : ";
    cin>>k;

    cout<<"Minimum swaps required bring elements less equal K together : "<<minimum_swaps(arr,k);

    return 0;
}