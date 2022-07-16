/* Find whether an array is a subset of another array
(https://practice.geeksforgeeks.org/problems/array-subset-of-another-array/0) */

#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> a,vector<int> b)
{
    unordered_map<int,int> mp;
    for(int i= 0;i<a.size();i++)
    {
        mp[a[i]] = 1;
    }
    for(int i = 0;i<b.size();i++)
    {
        if(mp[b[i]] != 1)
            return false;
    }
    return true;
}

int main()
{
    int n1,n2;
    cout<<"Enter size of first array : ";
    cin>>n1;

    vector<int> a(n1);
    cout<<"Enter element in 1st arr : ";
    for(int i=0;i<n1;i++)
    {
        cin>>a[i];
    }

    cout<<"Enter size of 2nd array : ";
    cin>>n2;

    vector<int> b(n2);
    cout<<"Enter element in 2nd arr : ";
    for(int i=0;i<n2;i++)
    {
        cin>>b[i];
    }


    cout<<"IS 2nd array is a subset of 1st array : "<<check(a,b);

    return 0;
}