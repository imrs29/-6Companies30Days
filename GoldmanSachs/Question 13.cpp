// decode the string


// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s,int &i){
        // code here
        string str = "";
        while(i < s.size() && s[i] != ']'){
            if(isdigit(s[i])){
                int ct = 0;
                while(i < s.size() && isdigit(s[i])){
                    ct = ct*10+(s[i]-'0');
                    i++;
                }
                i++;
                string res = decodedString(s,i);
                while(ct--)
                str += res;
                i++;
            }else{
                str += s[i];
                i++;
            }
        }
        return str;
        
        
        
    }
    public:
    string decodedString(string s){
        int i=0;
        return decodedString(s,i);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
