#include<iostream>
using namespace std;

void towerOfHanoi(int n, char source, char desti, char aux)
{
    if(n==1)
    {
        cout<<"Move disk 1 from "<<source<<" to "<<desti<<endl;
        return;
    }
    towerOfHanoi (n-1, source, aux, desti);
    cout<<"Move disk "<<n<<" from "<<source<<" to "<<desti<<endl;
    towerOfHanoi(n-1, aux, desti, source);
}

int main()
{
    int n;
    cout<<"Enter number of disks: ";
    cin>>n;
    towerOfHanoi(n,'A','C','B');
    return 0;
}
