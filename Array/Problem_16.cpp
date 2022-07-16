/* Count Inversion (https://practice.geeksforgeeks.org/problems/inversion-ofarray/0) */

#include<bits/stdc++.h>
using namespace std;

int count(vector<int> arr)
{
    int n = arr.size() , ans = 0;
    for(int i= 0;i<n;i++)
    {
        for(int j = i+1;j<n;j++)
        {
            if(arr[i] > arr[j])
                ans++;
        }
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

    int inversion_count = count(arr);
    cout<<"Total inversion count in an array : "<<inversion_count;
    
    return 0;
}