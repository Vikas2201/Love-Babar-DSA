/* Find the Union and Intersection of the two sorted arrays.
(https://practice.geeksforgeeks.org/problems/union-of-two-arrays/0) */

#include<bits/stdc++.h>
using namespace std;

vector<int> Union(vector<int> arr1 , vector<int> arr2)
{
    vector<int> arr;
    for(int i = 0;i< arr1.size();i++)
    {
        arr.push_back(arr1[i]);
    }
    for(int i = 0;i < arr2.size(); i++)
    {
        if (std::find(arr.begin(), arr.end(), arr2[i]) != arr.end())
        {
            continue;
        }
        else{
            arr.push_back(arr2[i]);
        }
    }
    return arr;    
}

vector<int> Intersection(vector<int> arr1,vector<int> arr2)
{
    unordered_map<int,int> mp;
    vector<int> arr;
    for(auto i : arr1)
    {
        mp[i]++;
    }
    for(auto i : arr2)
    {
        mp[i]++;
    }
    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        if(it->second > 1)
            arr.push_back(it->first);
    }
    return arr;
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

    vector<int> union_arr;
    union_arr = Union(arr1,arr2);
    cout<<"Union of Two Sorted Array : ";
    for(auto i : union_arr)
    {
        cout<<i<<" ";
    }

    vector<int> inter_arr;
    inter_arr = Intersection(arr1,arr2);
    cout<<"\nIntersection of Two Sorted Array : ";
    for(auto i : inter_arr)
    {
        cout<<i<<" ";
    }
    return 0;
}