/* Write a program to cyclically rotate an array by one.
(https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-byone/0) */

#include<bits/stdc++.h>
using namespace std;

void rotate(vector<int>& arr)
{
    int tmp = arr[arr.size()-1];
    for(int i = arr.size() - 1;i >= 0;i--)
    {
        arr[i] = arr[i-1];
    }
    arr[0] = tmp;
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

    rotate(arr);
    cout<<"After cyclically rotate an array by one : ";
    for(auto i : arr)
    {
        cout<<i<<" ";
    }
    return 0;
}