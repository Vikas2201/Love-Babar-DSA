/* Check if given graph is tree or not. [ IMP ] (https://www.geeksforgeeks.org/checkgiven-graph-tree/) */

#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
        int data;
        node* left;
        node* right;

        node(int value)
        {
            data = value;
            left = NULL;
            right = NULL;
        }
};

