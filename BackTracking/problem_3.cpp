/* Word Break Problem using Backtracking
(https://practice.geeksforgeeks.org/problems/word-break-part-2/0) */

#include<bits/stdc++.h>
using namespace std;

unordered_map<string,vector<string>> mp;

vector<string> make_words(string s,vector<string> dic)
{
    if(mp.find(s) != mp.end())
        return mp[s];
    vector<string> result; 
    for(auto w : dic)
    {
        if(s.substr(0,w.size()) == w)
        {
            if(s.length() == w.size())
                result.push_back(w);
        
            else
            {
                vector<string> temp = make_words(s.substr(w.size()),dic);
                for(auto t : temp)
                    result.push_back(w + " " + t);
            }
        }
    }
    mp[s] = result;
    return result;
}

int main()
{
    string s ;
    cout<<"Enter string : ";
    cin>>s;

    int n;
    cout<<"How many words are present in dictionary : ";
    cin>>n;

    vector<string> dic;
    cout<<"Enter words in dictionary : ";
    
    for(int i=0;i<n;i++)
    {
        cin>>dic[i];
    }

    vector<string> output;
    output = make_words(s,dic);

    cout<<"Output : ";
    for(auto i : output)
        cout<<i<<" ";

    return 0;
}