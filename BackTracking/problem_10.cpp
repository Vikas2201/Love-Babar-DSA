/* Tug of War (https://www.geeksforgeeks.org/tug-of-war/) */

#include<bits/stdc++.h>
using namespace std;

void tag_of_war(vector<int> arr,int n,int i , int sum1 , int sum2,vector<int> arr1,vector<int> arr2,int diff,vector<bool>& res)
{
    if(i == n)
    {
        if((abs(sum1 - sum2) <= diff) && (arr1.size() == (n+1)/2))
        {
            diff = abs(sum1 - sum2);
            for(int i=0;i<n;i++)
                res[i] = false;
            
            for(int i=0;i<arr1.size();i++)
                res[arr[i]] = true;
        }
        return ;
    }
    
    arr1.push_back(i);
    tag_of_war(arr,n,i+1,sum1+arr[i],sum2,arr1,arr2,diff,res);
    arr1.pop_back();

    arr2.push_back(i);
    tag_of_war(arr,n,i+1,sum1,sum2+arr[i],arr1,arr2,diff,res);
    arr2.pop_back();

    return ;
}

int main()
{
    int n;
    cout<<"Enter size of array : ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter elements in array : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    vector<int> arr1 , arr2;

    vector<bool> res(n);
    int diff = INT_MAX;
    tag_of_war(arr,n,0,0,0,arr1,arr2,diff,res);

    cout<<"Team 1 for tag of war : ";
    for(int i=0;i<n;i++)
        if(res[i])
            cout<<arr[i]<<" ";
    
    cout<<"Team 2 for tag of war : ";
    for(int i=0;i<n;i++)
        if(!res[i])
            cout<<arr[i]<<" ";

    return 0;
}
