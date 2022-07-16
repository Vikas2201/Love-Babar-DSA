/* Given an array which consists of only 0, 1 and 2. Sort the array without using any
sorting algo (https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s/0) */

#include<bits/stdc++.h>
using namespace std;

void Sort(vector<int>& arr)
{
    int c0 = 0 , c1 = 0 , c2 = 0;
    for(auto i : arr)
    {
        if(i == 0)
            c0++;
        if(i == 1)
            c1++;
        if(i == 2)
            c2++;
    }
    int i = 0;
    while (c0 > 0)
    {
        arr[i] = 0;
        i++;
        c0--;
    }
    while (c1 > 0)
    {
        arr[i] = 1;
        i++;
        c1--;
    }
    while (c2 > 0)
    {
        arr[i] = 2;
        i++;
        c2--;
    }
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

    Sort(arr);
    cout<<"After Sorting arr is : ";
    for(auto i : arr)
    {
        cout<<i<<" ";
    }
    return 0;
}