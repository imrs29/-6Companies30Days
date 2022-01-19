//Minimum operations to convert array A to B


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minInsAndDel(int A[], int B[], int N, int M) {
        // code here
        vector<int>v;
        for(int i = 0; i < N; i++){
            if(binary_search(B, B + M,A[i])){
                v.push_back(A[i]);
            }
        }
        return (N + M - (2*longest(v)));
    }
    
    int longest(vector<int>vec){
        vector<int>ans;
        if(vec.size() > 0)
        ans.push_back(vec[0]);
        for(int i=1;i<vec.size();i++){
            if(vec[i] > ans.back()){
                ans.push_back(vec[i]);
            }else{
                int id = lower_bound(ans.begin(), ans.end(), vec[i]) - ans.begin();
                ans[id] = vec[i];
            }
        }
        return ans.size();
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        cin>>N>>M;
        
        int A[N], B[M];
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<M; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.minInsAndDel(A,B,N,M) << endl;
    }
    return 0;
}  // } Driver Code Ends
