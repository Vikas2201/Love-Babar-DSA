/* Minimise the maximum difference between heights [V.IMP]
(https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1) */

#include<bits/stdc++.h>
using namespace std;

int getMinDiff(vector<int> arr, int n, int k)
{
    sort(arr.begin(),arr.end());
    int ans = arr[n-1]-arr[0];
    int smallest =arr[0]+k;
    int largest =arr[n-1]-k;
    int mi,ma;
    for(int i=0;i<n-1;i++)
    {
        mi= min(smallest, arr[i+1]-k);
        ma= max(largest,arr[i]+k);
        if(mi<0)
        {
            continue;
            ans= min(ans,ma-mi);
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

    int k;
    cout<<"Enter the value of k : ";
    cin>>k;
    int maxdiff = getMinDiff(arr,arr.size(),k);
    cout<<"Largest sum contiguous Subarray : "<<maxdiff;
    
    return 0;
}