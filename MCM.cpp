// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int solve(int arr[], int i, int j)
    {
        // Base Case
        if(i >= j) // if arr size < 2 then we dont get any matrix
            return 0;
        
        // calculate for k sub problems
        int ans = INT_MAX;
        for(int k = i; k < j; k++)
        {
            int temp_ans = solve(arr, i, k) + solve(arr, k+1, j) + (arr[i-1]*arr[k]*arr[j]);
            ans = min(ans, temp_ans);
        }
        return ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        return solve(arr, 1, N-1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends
