// Guess Number Higher or Lower II

class Solution {
public:
    int getMoneyAmount(int n) {
        
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        for(int i = 2; i <= n; i++){
            
            
            for(int j = 1; j <= n - i + 1; j++){
                int high = j + i - 1;
                int curr = INT_MAX;
                
                for(int k = j; k <= high; k++)
                if(k == j){
                    curr = min(curr, k + dp[k+1][high]);
                }else if(k  == high){
                    curr = min(curr, k + dp[j][k-1]);
                }else
                {
                    int maxi = max(dp[j][k - 1], dp[k + 1][high]);
                    curr = min(curr, k + maxi);
            
                    }
                
                dp[j][high] = curr;
                
                }
            }
        return dp[1][n];   
    }
};
