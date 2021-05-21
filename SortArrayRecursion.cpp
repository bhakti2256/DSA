#include<iostream>
#include<vector>
using namespace std;

void sort(vector<int>& v);
void insert(vector<int>& v, int temp);

int main()
{
    int n;
    vector<int> v;
    cout<<"Enter number of elements: ";
    cin>>n;
    int elem;
    while(n--)
    {
        cout<<"Enter element: ";
        cin>>elem;
        v.push_back(elem);
    }
    sort(v);
    cout<<"Sorted array: ";
    for(auto i:v)
    {
        cout<<i<<" ";
    }
    return 0;
}

void sort(vector<int>& v)
{
    if(v.size()==1)
        return;
    int temp = v[v.size()-1]; //last element
    v.pop_back(); //reduce the problem
    sort(v); //recursive call to reduced input
    insert(v,temp); // insert the previously removed element
}

void insert(vector<int>& v, int temp)
{
    //If array is empty or temp is greater than last elem, then simply insert
    if(v.size()==0 || v[v.size()-1] <= temp)
    {
        v.push_back(temp);
        return;
    }
    int last_elem = v[v.size()-1]; //store last elem
    v.pop_back(); //remove last elem from array
    insert(v,temp); // recursively call insert function on reduced input
    v.push_back(last_elem); //push back the removed element
}
