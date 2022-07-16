/* Minimum no. of Jumps to reach end of an array
(https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0) */

#include<bits/stdc++.h>
using namespace std;

int minimum_jump(vector<int> arr)
{
    int maxcurrent = 0 , maxreach = 0 , jump = 0;
    for(int i=0;i<arr.size()-1;i++)
    {
        if(i+arr[i] > maxcurrent)
            maxcurrent = i+arr[i];
        if(i == maxreach)
        {
            jump++;
            maxreach = maxcurrent;
        }
    }
    return jump;
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

    int minjump = minimum_jump(arr);
    cout<<"Minimum no. of Jumps to reach end of an array : "<<minjump;
    
    return 0;
}