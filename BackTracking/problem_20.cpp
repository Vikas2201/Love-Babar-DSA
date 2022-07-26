/* Implement Stack from Scratch
(https://www.tutorialspoint.com/javaexamples/data_stack.htm) */

#include<bits/stdc++.h>
using namespace std;

class Stack
{
    private:
        int top;
        int n;
        int arr[];
    
    public:
        Stack(int size)
        {
            n = size;
            top = -1;
            arr[n];
        }

        bool push(int x)
        {
            if(top > n)
                return false;
            arr[++top] = x;
            return true;
        }

        bool pop()
        {
            if(top < 0)
                return false;
            top--;
            return true;
        }

        int peek()
        {
            if(top < 0 || top > n)
                return -1;
            return arr[top];
        }

        bool empty()
        {
            if(top < 0)
                return true;
            return false;
        }
};

int main()
{
    Stack s(5);
    cout<<s.push(10);
    cout<<s.push(20);
    cout<<s.push(30);
    cout<<s.push(40);
    cout<<s.push(50);
    cout<<s.push(60);
    cout<<s.pop();
    cout<<s.pop();
    cout<<s.peek();
    return 0;
}