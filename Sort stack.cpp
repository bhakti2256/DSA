#include<iostream>
#include<stack>
using namespace std;

void sort(stack<int>& s);
void insert(stack<int>& s, int temp);

int main()
{
    int n;
    stack<int> s;
    cout<<"Enter number of elements: ";
    cin>>n;
    int elem;
    while(n--)
    {
        cout<<"Enter element: ";
        cin>>elem;
        s.push(elem);
    }
    sort(s);
    cout<<"Stack sorted from bottom: ";
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}

void sort(stack<int>& s)
{
    if(s.size()==1)
        return;
    int temp = s.top(); //last element
    s.pop(); //reduce the problem
    sort(s); //recursive call to reduced input
    insert(s,temp); // insert the previously removed element
}

void insert(stack<int>& s, int temp)
{
    //If array is empty or temp is greater than last elem, then simply insert
    if(s.size()==0 || s.top() <= temp)
    {
        s.push(temp);
        return;
    }
    int last_elem = s.top(); //store last elem
    s.pop(); //remove last elem from array
    insert(s,temp); // recursively call insert function on reduced input
    s.push(last_elem); //push back the removed element
}
