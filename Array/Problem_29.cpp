/* Find the triplet that sum to a given value
(https://practice.geeksforgeeks.org/problems/triplet-sum-in-array/0) */

#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> arr,int sum)
{
    sort(arr.begin(),arr.end());
    for(int i = 0;i<arr.size()-2;i++)
    {
        int l = i+1 , r = arr.size() - 1;
        while (l < r)
        {
            if(arr[i]+arr[l]+arr[r] == sum)
                return true;
            else if(arr[i]+arr[l]+arr[r] < sum)
                l++;
            else
                r--;
        }
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

    int sum;
    cout<<"Enter the value of sum : ";
    cin>>sum;

    cout<<"Is there any triplet that sum to a given value : "<<check(arr,sum);

    return 0;
}