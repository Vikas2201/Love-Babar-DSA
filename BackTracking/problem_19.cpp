/* Find the K-th Permutation Sequence of first N natural numbers
(https://www.geeksforgeeks.org/find-the-k-th-permutation-sequence-of-first-nnatural-numbers/) */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter value of n : ";
    cin>>n;

    int k;
    cout<<"Enter value of k : ";
    cin>>k;

    int fact = 1;
    vector<int> num;
    for(int i=1;i<n;i++)
    {
        fact = fact * i;
        num.push_back(i);
    }
    num.push_back(n);

    string str = "";
    k = k-1;
    while(1)
    {
        str += to_string(num[k / fact]);
        num.erase(num.begin() + k/fact);
        if(num.size() == 0)
            break;
        k = k % fact;
        fact = fact/num.size();
    }

    cout<<k<<"th permutation of first n natural number : "<<str;
    return 0;
}