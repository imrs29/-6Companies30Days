// Amend The Sentence

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string amendSentence (string s)
    {
        // your code here
        for(int i = 0; i < s.length(); i++){
    
        if(s[i] >= 'A' && s[i] <= 'Z'){
        s[i] += 32;
        
        if(i != 0)
        cout << " ";
        
        cout << s[i];
        }else
        cout << s[i];
        }
    }
};

// { Driver Code Starts.
int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		Solution ob;
		cout << ob.amendSentence (s) << endl;
	}
}  // } Driver Code Ends
