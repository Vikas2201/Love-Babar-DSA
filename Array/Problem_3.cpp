/* Find the "Kth" max and min element of an array
(https://practice.geeksforgeeks.org/problems/kth-smallest-element/0) */

#include<bits/stdc++.h>
using namespace std;

int min_ele(vector<int> arr,int k)
{
    priority_queue<int> pq;
    for(int i = 0;i<k;i++)
    {
        pq.push(arr[i]);
    }
    for(int i = k;i<arr.size();i++)
    {
        if(pq.top() > arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

int max_ele(vector<int> arr,int k)
{
    priority_queue<int> pq;
    for(int i = 0;i<k;i++)
    {
        pq.push(arr[i]);
    }
    for(int i = k;i<arr.size();i++)
    {
        if(pq.top() < arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
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
    cout<<"Enter Value of k : ";
    cin>>k;

    cout<<"Maximum "<<k<<"th element in arr : "<<max_ele(arr,k)<<endl;
    cout<<"Minimum "<<k<<"th element in arr : "<<min_ele(arr,k);
    return 0;
}