/* find all pairs on integer array whose sum is equal to given number
(https://practice.geeksforgeeks.org/problems/count-pairs-with-givensum5022/1) */

#include<bits/stdc++.h>
using namespace std;

int count(vector<int>& arr,int k)
{
    int c = 0;
    for(int i=0;i<arr.size();i++)
    {
        if(std::find(arr.begin(),arr.end(),k-arr[i]) != arr.end())
            c++;
    }
    return c;
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
    cout<<"Enter the value of sum : ";
    cin>>k;

    int pair_count = count(arr,k);
    cout<<"Total count in an array : "<<pair_count;
    
    return 0;
}