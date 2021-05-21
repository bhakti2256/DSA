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
    v.pop_back();
    sort(v); //recursive call to reduced input
    insert(v,temp); // insert the previously removed element
}

void insert(vector<int>& v, int temp)
{
    if(v.size()==0 || v[v.size()-1] <= temp)
    {
        v.push_back(temp);
        return;
    }
    int lastelem = v[v.size()-1];
    v.pop_back();
    insert(v,temp);
    v.push_back(lastelem);
}
