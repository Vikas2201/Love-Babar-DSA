/* find common elements In 3 sorted arrays
(https://practice.geeksforgeeks.org/problems/common-elements1132/1) */

#include<bits/stdc++.h>
using namespace std;

vector<int> common(vector<int> A,vector<int> B,vector<int> C)
{
    unordered_map<int,int> mp;
    int i=0,j=1;
    while(i<A.size())
    {
        if(A[i] != A[j])
        {
            mp[A[i]]++;
            i++;j++;
        }
        else
        {
            mp[A[i]]++;
            while(j< A.size() && A[j] == A[i])
            {
                j++;
            }
            i = j;
            j++;
        }
    }
    i=0;
    j=1;
    while(i<B.size())
    {
        if(B[i]!=B[j])
        {
            mp[B[i]]++;
            i++;j++;
        }
        else
        {
            mp[B[i]]++;
            while(j< B.size() && B[j] == B[i])
            {
                j++;
            }
            i=j;
            j++;
        }
    }
    i=0;
    j=1;
    while(i< C.size())
    {
        if(C[i] != C[j])
        {
            mp[C[i]]++;
            i++;
            j++;
        }
        else
        {
            mp[C[i]]++;
            while(j< C.size() && C[j]==C[i])
            {
                j++;
            }
            i=j;
            j++;          
        }
    }

    vector<int> ans;
    for(auto it = mp.begin();it != mp.end();it++)
    {
        if(it->second >= 3)
            ans.push_back(it->first);
    }

    return ans;
}

int main()
{
    int n1;
    cout<<"Enter size of 1st arr : ";
    cin>>n1;

    vector<int> A(n1);
    cout<<"Enter element in 1st arr : ";
    for(int i=0;i<n1;i++)
    {
        cin>>A[i];
    }

    int n2;
    cout<<"Enter size of 2nd arr : ";
    cin>>n2;

    vector<int> B(n2);
    cout<<"Enter element in 2nd arr : ";
    for(int i=0;i<n2;i++)
    {
        cin>>B[i];
    }

    int n3;
    cout<<"Enter size of 3rd arr : ";
    cin>>n3;

    vector<int> C(n3);
    cout<<"Enter element in 3rd arr : ";
    for(int i=0;i<n3;i++)
    {
        cin>>C[i];
    }

    vector<int> ans;
    ans = common(A,B,C);
    cout<<"common elements In 3 sorted arrays : ";
    for(auto i : ans)
        cout<<i<<" ";
    
    return 0;
}

