/* Move all the negative elements to one side of the array
(https://www.geeksforgeeks.org/move-negative-numbers-beginning-positiveend-constant-extra-space/) */

#include<bits/stdc++.h>
using namespace std;

void move_neg(vector<int>& arr)
{
    int j = 0;
    for(int i = 0;i< arr.size() ; i++)
    {
        if(arr[i] < 0)
        {
            if(i != j)
            {
                swap(arr[i],arr[j]);
            }
            j++;
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

    move_neg(arr);
    cout<<"After moving all negative elements to one side of the array : ";
    for(auto i : arr)
    {
        cout<<i<<" ";
    }
    return 0;
}