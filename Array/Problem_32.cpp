/* Three way partitioning of an array around a given value
(https://practice.geeksforgeeks.org/problems/three-way-partitioning/1) */

#include<bits/stdc++.h>
using namespace std;

void three_way_partition(vector<int>& arr,int a , int b)
{
    int start = 0 , mid = 0 , end = arr.size() -1;
    while(mid <= end)
    {
        if(arr[mid] < a)
            swap(arr[mid++],arr[start++]);
        else if(arr[mid] > b)
            swap(arr[mid],arr[end--]);
        else
            mid++;
    }
}

int main()
{
    int n;
    cout<<"Enter size of array : ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter elements in arr : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int a , b;
    cout<<"Enter range : ";
    cin>>a>>b;

    three_way_partition(arr,a,b);
    cout<<"After partiting array : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}