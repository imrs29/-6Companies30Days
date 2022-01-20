//Number of distict Words with k maximum contiguous vowels

// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    long p(long a, long b, long c){
        long ans = 1ll;
        a = a % c;
        if(a == 0)
        return 0;
        
        while(b > 0){
            if(b & 1)
            ans = (ans * a) % c;
            b = b>>1;
            a = (a*a) % c;
        }
        return ans;
    }
  public:
    int kvowelwords(int N, int K) {
        // Write Your Code here
        
        long MOD = 1000000007;
        long dp[N+1][K+1] ={0};
        long tot = 1,i,j;
        for(i = 1; i <= N; i++){
            dp[i][0] = tot*21;
            dp[i][0] %= MOD;
            tot = dp[i][0];
            
            for(j = 1; j <= K; j++){
                if(j > i)
                dp[i][j] = 0;
                else if(j == i)
                dp[i][j] = p(5ll,i,MOD);
                else
                dp[i][j] = dp[i-1][j-1]*5;
                
                dp[i][j] %= MOD;
                tot += dp[i][j];
                tot %= MOD;
            }
        }
       return tot; 
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;int K;
        cin >>N>>K;
        
        Solution ob;
        int ans = ob.kvowelwords(N,K);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends
