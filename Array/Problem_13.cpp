/* Kadane's Algo [V.V.V.V.V IMP]
(https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0) */

#include<bits/stdc++.h>
using namespace std;

int kadane(vector<int> arr)
{
    int maxsum = INT_MIN , cursum = 0;
    for(int i = 0;i<arr.size();i++)
    {
        cursum += arr[i];
        if(cursum > maxsum)
            maxsum = cursum;
        if(cursum < 0)
            cursum = 0;
    }
    return maxsum;
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

    int maxsum = kadane(arr);
    cout<<"Max subarray sum is : "<<maxsum;
    
    return 0;
}