//


// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int maxCoins(vector<int>&A,int n)
    {
	    //Write your code here
	    int dp[n][n]={0};
      for(int i=0;i<n;i++)
      { 
        dp[i][i]=A[i];
      }
      for(int i=0;i<n-1;i++)
      {  
        dp[i][i+1]=max(A[i],A[i+1]);
      }
     for(int gap=2;gap<=n-1;gap++)
      { 
       for(int i=0;i<n;i++)
        { 
         int j=i+gap;
         if(j>=n)
        { 
           break; 
        }
        dp[i][j]=max(A[i]+min(dp[i+2][j],dp[i+1][j-1]),A[j]+min(dp[i+1][j-1],dp[i][j-2]));
      }
   }
   return dp[0][n-1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int>A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}
  // } Driver Code Ends
