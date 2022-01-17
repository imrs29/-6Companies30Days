//Generate Parentheses


// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void check(int n,int l,int r,vector<string>&res,string s){
        if(l > n || r > n || r > l)
            return;
        if(l == n && r == n)
            {
                res.push_back(s);   
            }
        check(n,l+1,r,res,s+'(');
        check(n,l,r+1,res,s+')');
          
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        int l=0 , r=0;
        vector<string>ans;
        string s = "";
        check(n,l,r,ans,s);
        return ans;
    }
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends
