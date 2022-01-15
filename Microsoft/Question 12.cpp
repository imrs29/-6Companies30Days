//Find All Four Sum Numbers 


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        vector<vector<int>> res;
            
            if(arr.empty())
                    return res;
            
            int n = arr.size();
            sort(arr.begin(), arr.end());
            
            for(int i = 0; i < n; i++){
                    for(int j = i + 1; j < n; j++){
                            
                            int target2 = k - arr[j] - arr[i];
                            
                            int left = j + 1;
                            int right = n - 1;
                            
                            while(left < right){
                                    
                                    int twoSum = arr[left] + arr[right];
                                    
                                    if(twoSum < target2)
                                            left++;
                                    
                                    else if(twoSum > target2)
                                            right--;
                                    
                                    else{
                                            
                                            vector<int>quad(4,0);
                                            quad[0] = arr[i];
                                            quad[1] = arr[j];
                                            quad[2] = arr[left];
                                            quad[3] = arr[right];
                                            res.push_back(quad);
                                            
                                            while(left < right && arr[left] == quad[2])
                                                    left++;
                                            
                                            while(left < right && arr[right] == quad[3])
                                                    right--;
                                    }
                            }
                            
                            while(j + 1 < n && arr[j + 1] == arr[j])
                                    j++;
                    }
                    
                    while(i+1 < n && arr[i + 1] == arr[i])
                            i++;
            }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends
