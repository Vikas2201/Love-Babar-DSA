/* Smallest Subarray with sum greater than a given value
(https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sumgreater-than-x/0) */

#include<bits/stdc++.h>
using namespace std;

int minimum_length_subarray(vector<int> arr,int x)
{
    int i = 0 , j = 0 , sum = 0 , ans = INT_MAX;
    while(i < arr.size())
    {
        sum += arr[i];
        if(sum > x)
        {
            while(sum > x)
            {
                ans = min(ans,i-j+1);
                sum -= arr[j];
                j++;
            }
        }
        i++;
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

    int x;
    cout<<"Enter the value of x : ";
    cin>>x;

    cout<<"Smallest length of Subarray with sum greater than a "<<x<<" : "<<minimum_length_subarray(arr,x);

    return 0;
}