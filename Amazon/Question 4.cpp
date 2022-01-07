//Brackets in Matrix Chain Multiplication

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string matrixChainOrder(int p[], int n){
        // code here
        vector<vector<int>>dp(n,vector<int>(n,0));
        vector<vector<string>>sdp(n,vector<string>(n,""));
        int si,ei;
        for(int gap=1;gap<n;gap++){
            for(si=0,ei=gap;ei<n;si++,ei++){
                if(ei-si==1){
                    dp[si][ei]=1;
                    
                     sdp[si][ei] = si+'A';
                    continue;
                }
                int minR=(int)1e9;
                string minstr="";
                for(int cut=si+1;cut<ei;cut++){
                    int lans=dp[si][cut];
                    int rans=dp[cut][ei];
                    if(lans+rans+p[si]*p[ei]*p[cut]<minR){
                        minR=lans+rans+p[si]*p[ei]*p[cut];
                        minstr="(" + sdp[si][cut] + sdp[cut][ei] + ")";
                    }
                }
                 dp[si][ei] = minR;
                sdp[si][ei] = minstr;
            }
        }
        
        return sdp[0][n-1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
