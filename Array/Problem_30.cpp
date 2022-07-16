/* Chocolate Distribution problem
(https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem/0) */

#include<bits/stdc++.h>
using namespace std;

int min_distribution(vector<int> arr,int student)
{
    sort(arr.begin(),arr.end());
    int ans = INT_MAX;
    for(int i=0;i+student-1 < arr.size();i++)
    {
        int d = arr[i+student-1] - arr[i];
        ans = min(ans,d);
    }
    return ans;
}

int main()
{
    int n;
    cout<<"Enter no. of packets : ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter values of chocolate in each packet : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int student;
    cout<<"Enter how many students we have : ";
    cin>>student;

    cout<<"Minimum difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is : "<<min_distribution(arr,student);

    return 0;
}