/* find Largest sum contiguous Subarray
(https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0) */ 

#include<bits/stdc++.h>
using namespace std;

int cont_sum(vector<int> arr)
{
    int currsum = 0 , maxsum = INT_MIN;
    for(int i = 0;i < arr.size();i++)
    {
        currsum += arr[i];
        if(currsum < maxsum)
        {
            maxsum = currsum;
        }
        if(currsum < 0)
        {
            currsum = 0;
        }
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

    int maxsum = cont_sum(arr);
    cout<<"Largest sum contiguous Subarray : "<<maxsum;
    
    return 0;
}