/* Trapping Rain water problem
(https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1) */

#include<bits/stdc++.h>
using namespace std;

int trap_water(vector<int> arr)
{
    int n = arr.size();
    vector<int> left(n);
    vector<int> right(n);

    left[0] = arr[0];
    for(int i=1;i<n;i++)
    {
        left[i] = max(left[i-1],arr[i]);
    }
    right[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--)
    {
        right[i] = max(right[i+1],arr[i]);
    }

    int gap = 0;
    for(int i=0;i<n;i++)
    {
        gap = gap + abs(min(left[i],right[i]) - arr[i]);
    }

    return gap;
}

int main()
{
    int n;
    cout<<"Enter no. of bulidings : ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter height of bulidings : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<"Total water trap between buildings : "<<trap_water(arr);

    return 0;
}