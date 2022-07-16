/* Next Permutation (https://leetcode.com/problems/next-permutation/) */

#include<bits/stdc++.h>
using namespace std;

void next_permutation(vector<int>& arr)
{
    int n = arr.size() , i;
    for(i = n-2;i>= 0;i--)
    {
        if(arr[i] < arr[i+1])
            break;
    }

    if(i >= 0)
    {
        for(int j = n-1;j >= 0;j--)
        {
            if(arr[j] > arr[i])
            {
                swap(arr[j],arr[i]);
                break;
            }
        }
    }
    return ;
}

int main()
{
    int n;
    cout<<"Enter digit in number : ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter element in arr : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    next_permutation(arr);
    cout<<"Next Permutation of a number : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
    }
    
    return 0;
}