//First non-repeating character in a stream

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    
		   vector<int> freq(26,0);
		   string str = "";
		   vector<char> order;
		   int n = A.length();
		   for(int i = 0; i < n; i++){
		       if(!freq[A[i] - 'a']){
		           order.push_back(A[i]);
		       }
		       freq[A[i]-'a']++;
		       int first = 0;
		       int m = order.size();
		       for(int j = 0; j < m; j++){
		           if(freq[order[j] - 'a']==1){
		               str.push_back(order[j]);
		               first = 1;
		               break;
		           }
		       }
		       if(first == 0)
		       str.push_back('#');
		   }
		   return str;
		   
		   
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
