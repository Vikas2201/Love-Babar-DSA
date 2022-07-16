/* Rearrange the array in alternating positive and negative items with O(1) extra space
(https://www.geeksforgeeks.org/rearrange-array-alternating-positive-negativeitems-o1-extra-space/) */

#include<bits/stdc++.h>
using namespace std;

void rotate(vector<int>& arr)
{
    int n = arr.size();
    int neg = -1;
    for(int i=0;i<n;i++)
    {
        if(neg >= 0)
        {
            if((arr[i] > 0 && arr[neg] < 0) || (arr[i] < 0 && arr[neg] > 0))
            {
                swap(arr[i],arr[neg]);
                if(i - neg >= 2)
                    neg += 2;
                else
                    neg = -1;
            }
        }
        if(neg == -1)
        {
            if((arr[i] >= 0 && i < n) || (arr[i] < 0 && i < n))
                neg = i;
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

    rotate(arr);
    cout<<"Array in alternating positive and negative items : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}