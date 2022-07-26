/* Find Maximum number possible by doing at-most K swaps
(https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps/0) */

#include<bits/stdc++.h>
using namespace std;

string Max;
void maximum_number(string str,int k)
{
    if(k == 0)
    {
        return ;
    }
    
    for(int i=0;i<str.size()-1;i++)
    {
        for(int j=1;j<str.size();j++)
        {
            swap(str[i],str[j]);
            if (str.compare(Max) > 0)
                Max = str;
            maximum_number(str,k-1);
            swap(str[i],str[j]);
        }
    }
}

int main()
{
    string str;
    cout<<"Enter numeric string : ";
    cin>>str;

    int k;
    cout<<"Enter value of k : ";
    cin>>k;

    maximum_number(str,k);
    cout<<"Maximum number possible : "<<Max;
    return 0;
}