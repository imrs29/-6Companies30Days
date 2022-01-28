// Largest Number in K swaps

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    void solve(string str, int k, string &res, int first){
        
        if(k == 0 || first >= str.size()){
            return;
        }
       
        char ch = str[first];
        
        for(int i = first+1; i < str.size(); i++){
            if(str[i] > ch){
                ch = str[i];
            }
            
        }
        
        if(ch == str[first]){
            if(res.compare(str) < 0)
            res = str;
            solve(str, k, res, first + 1);
        }else{
            for(int i = first+1 ; i < str.size(); i++){
                if(str[i] == ch){
                    swap(str[first], str[i]);
                    if(res.compare(str) < 0)
                    res = str;
                    solve(str, k-1, res, first+1);
                    swap(str[first] , str[i]);
                }
            }
        }
        
        
    }
    string findMaximumNum(string str, int k)
    {
       // code here.
       
       string res = str;
       solve(str, k, res, 0);
       return res;
      
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends
