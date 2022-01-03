//Total Decoding Messages


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	    const int MOD = 1e9+7;
		int CountWays(string str){
		    // Code here
		    int n = str.length();
		    vector<long long>dp(n+1,0);
		    dp[n] = 1;
		    for(int i = n-1; i>=0;i--){
		        if(str[i]=='0')
		        continue;
		        dp[i]=dp[i+1];
		        if(i==n-1)
		        continue;
		        string st=str.substr(i,2);
		        if(st<="26")
		        dp[i]+=dp[i+2];
		        dp[i] %= MOD;
		        
		    }
		    return dp[0]%MOD;
		    
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
