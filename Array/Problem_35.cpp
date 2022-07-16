/* Median of 2 sorted arrays of equal size
(https://practice.geeksforgeeks.org/problems/find-the-median0527/1) */

#include<bits/stdc++.h>
using namespace std;

double median_value(vector<int> a,vector<int> b)
{
    int n = a.size();
    int i = 0 , j = 0 , c = 0;
    double m1  = 0 ,m2 = 0;
    while(c <= n)
    {
        m2 = m1;
        if(i == n)
        {
            m1 = b[0];
            break;
        }
        else if(j == n)
        {
            m1 = a[0];
            break;
        }
        if(a[i] <= b[j])
        {
            m1 = a[i];
            i++;
        }
        else
        {
            m1 = b[j];
            j++;
        }
        c++;
    }
    return (m1+m2)/2;
}

int main()
{
    int n;
    cout<<"Enter size of array : ";
    cin>>n;

    vector<int> a(n);
    cout<<"Enter element in 1st arr : ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    vector<int> b(n);
    cout<<"Enter element in 2nd arr : ";
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }


    cout<<"median two sorted array : "<<median_value(a,b);

    return 0;
}