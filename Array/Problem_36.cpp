/* Median of 2 sorted arrays of different size (https://www.geeksforgeeks.org/medianof-two-sorted-arrays-of-different-sizes/) */

#include<bits/stdc++.h>
using namespace std;

double median_value(vector<int> a , vector<int> b)
{
    int n = a.size() , m = b.size();
    if(n > m)
    {
        return median_value(b,a);
    }
    int start = 0 , end = n;
    while(start <= end)
    {
        int i1 = (start+end)/2;
        int i2 = (n+m+1)/2 - i1;

        double max1 = (i1 == 0) ?  INT_MIN : a[i1-1];
        double min1 = (i1 == n) ? INT_MAX : a[i1];

        double max2 = (i2 == 0) ? INT_MIN : b[i2-1];
        double min2 = (i2 == m) ? INT_MAX : b[i2];

        if((max1 <= min2) && (max2 <= min1))
        {
            if((n+m)%2 == 0)
            {
                return (max(max1,max2) +  min(min1,min2))/2;
            }
            else
                return max(max1,max2);
        }
        else if(max1 > min2)
        {
            end = i1 -1;
        }
        else
        {
            start = i1+1;
        }
    }
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


    cout<<"median two sorted array : "<<median_value(a,b);

    return 0;
}