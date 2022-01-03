//Number following a pattern

// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        int n = S.length();
        int count = 1;
        stack<int> st;
        string res = "";
        for(int i = 0; i < n;i++){
            if(S[i] == 'D'){
                st.push(count);
                count++;
            }else{
                st.push(count);
                count++;
                while(!st.empty()){
                    char ch = st.top() + '0';
                    res += ch;
                    st.pop();
                    
                }
            }
        }
        st.push(count);
        while(!st.empty()){
            char ch = st.top()+'0';
            res+=ch;
            st.pop();
        }
        return res;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends
