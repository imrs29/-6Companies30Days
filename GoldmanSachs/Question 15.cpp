//Array Pair Sum Divisibility Problem

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i = 0; i < n; i++){
            mp[(nums[i] %k+k)%k]++;
        }
        bool res = true;
        if(mp[0] % 2 !=0){
            res = false;
            return res;
        }
        for(int i = 1; i < k; i++){
            if(mp[i] != mp[k-i]){
                res = false;
                break;
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends
