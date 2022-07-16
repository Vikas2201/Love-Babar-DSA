/* find maximum product subarray
(https://practice.geeksforgeeks.org/problems/maximum-productsubarray3604/1) */

#include<bits/stdc++.h>
using namespace std;

double max_prod_arr(vector<int> arr)
{
    double max_prod = 0 , curr_prod = 1;
    for(int i=0 ; i< arr.size();i++)
    {
        curr_prod *= arr[i];
        max_prod = max(max_prod,curr_prod);
        if(curr_prod == 0)
            curr_prod = 1;
    }
    return max_prod;
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

    cout<<"Maximum product subarray : "<<max_prod_arr(arr);

    return 0;
}