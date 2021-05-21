#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int>& s, int pos);

int main()
{
    int n;
    stack<int> s;
    cout<<"Enter size of stack: ";
    cin>>n;
    if(n==0)
        return 0;
    int elem;
    while(n--)
    {
        cout<<"Enter element: ";
        cin>>elem;
        s.push(elem);
    }
    int pos;
    cout<<"Enter position to be deleted: ";
    cin>>pos;
    solve(s,pos);
    cout<<"Stack after deletion: ";
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}

void solve(stack<int>& s, int pos)
{
    if(pos==1) //pos=1 means stack top = element to be deleted
    {
        s.pop();
        return;
    }
    int topElem = s.top(); //store the top element
    s.pop(); // reduce the size of stack
    solve(s, pos-1); //apply solve on reduced stack
    s.push(topElem); //push the removed element in the stack
}
