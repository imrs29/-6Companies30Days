//Unit Area of largest region of 1's 

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
     int dfs(vector<vector<int>> &grid, int i, int j,int n, int m){
            if(i < 0 || j < 0)
                    return 0;
            if(i >= n || j >= m || grid[i][j] == 0)
                    return 0;
                    
            static int x[8] = {-1,-1,-1,1,1,1,0,0};
            static int y[8] = {1,0,-1,1,0,-1,1,-1};
            
            grid[i][j] = 0;
            int ans = 1;
                    
            for(int k=0;k<=8;k++){
                
            ans += dfs(grid, i+x[k], j+y[k],n,m);
            }
            return ans;
    }
    
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        
        int n = grid.size();
        int m = grid[0].size();
          if(grid.size() == 0)
                    return 0;
            int res = 0;
            for(int i = 0; i < grid.size(); i++)
            {
                    for(int j = 0; j < grid[0].size(); j++){
                            if(grid[i][j] == 1){
                                    res=max(res,dfs(grid, i , j,n,m));
                                    
                            }
                    }
            }
        return res;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
