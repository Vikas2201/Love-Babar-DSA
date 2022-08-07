/* Given "n" appointments, find the conflicting appointments
(https://www.geeksforgeeks.org/given-n-appointments-find-conflictingappointments/) */

#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
        int data;
        node* left;
        node* right;

        node(int val)
        {
            data = val;
            left = NULL;
            right = NULL;
        }
};

