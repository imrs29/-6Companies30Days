//Express as sum of power of natural numbers 

// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    long long numOfWays(int n, int x)
    {
        // code here
        long long dp[n+1];
        memset(dp,0.,sizeof(dp));
        dp[0]=1;

        for(long long i=1;i<=n;i++)
        {
            for(long long j=n;j>=i;j--)
            {
                long long y=pow(i,x);
                if(j>=y)dp[j]+=dp[j-y];
            }
        }
        return dp[n];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
