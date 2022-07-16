/* Find the maximum and minimum element in an array
(https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/) */

#include<bits/stdc++.h>
using namespace std;

vector<int> min_max(vector<int> arr)
{
    int Min = INT_MAX , Max = INT_MIN;
    for(auto i : arr)
    {
        if(i > Max)
        {
            Max = i;
        }
        else if(i < Min)
        {
            Min = i;
        }
    }
    vector<int> ans;
    ans.push_back(Max);
    ans.push_back(Min);
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

    vector<int> ans;
    ans = min_max(arr);
    cout<<"Maximum element in arr : "<<ans[0]<<endl;
    cout<<"Minimum element in arr : "<<ans[1];
    return 0;
}