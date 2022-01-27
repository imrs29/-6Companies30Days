// Stone Game

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        int sum=0;
        for(auto p:piles){
            sum+=p;
        }
        vector<vector<int> > dp(piles.size()+1,vector<int>(piles.size()+1));
        for(int i=0;i<n;i++){
            dp[i][i]=piles[i];
        }
        for(int i=0;i<n-1;i++){
            dp[i][i+1]=max(piles[i],piles[i+1]);
        }
        for(int len=3;len<=n;len++){
            int i=0,j=len-1;
            while(j<n){
                int ans1=piles[i]+min(dp[i+2][j],dp[i+1][j-1]);
                int ans2=piles[j]+min(dp[i][j-2],dp[i+1][j-1]);
                dp[i][j]=max(ans1,ans2);
                i++;
                j++;
            }
            
        }
       
        return dp[0][n-1]>(sum-dp[0][n-1]);
    }
};
