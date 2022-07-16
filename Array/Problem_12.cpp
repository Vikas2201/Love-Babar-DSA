/* Merge 2 sorted arrays without using Extra space.
(https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1) */

#include<bits/stdc++.h>
using namespace std;

void Merge(vector<int>& arr1,vector<int>& arr2)
{
    int i = 0 , j = 0 , k = arr1.size()-1;
    while(i <= k && j < arr2.size())
    {
        if(arr1[i] < arr2[j])
            i++;
        else
        {
            swap(arr2[j++],arr1[k--]);
        }
    }
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
    return ;
}

int main()
{
    int n;
    cout<<"Enter size of arr1 : ";
    cin>>n;

    int m;
    cout<<"Enter size of arr2 : ";
    cin>>m;

    vector<int> arr1(n);
    cout<<"Enter element in arr1 : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }

    vector<int> arr2(m);
    cout<<"Enter element in arr2 : ";
    for(int i=0;i<m;i++)
    {
        cin>>arr2[i];
    }

    Merge(arr1,arr2);
    cout<<"After Merging arr will be : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<m;i++)
    {
        cout<<arr2[i]<<" ";
    }
    
    return 0;
}
