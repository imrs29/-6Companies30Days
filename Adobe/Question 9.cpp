//Next higher palindromic number using the same set of digits


// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    string nextPalin(string N) { 
        //complete the function here
        
        if(N.size() <= 3)
        
        return "-1";
        
        int ct = 0;
        int j = (N.size()/2)-1;
        int i;
        for(i=(N.size()/2)-1;i>0;i--)
        {
            if(N[i]>N[i-1])
            {
                ct = 1;
                while(N[j] <= N[i-1])
                {
                    j--;
                }
            }
            if(ct == 1)
            break;
        }
        if(ct == 0)
        return "-1";
        swap(N[i-1],N[j]);
        int z=(N.size()/2);
        reverse(N.begin()+i,N.begin()+z);
        for(int i=0;i<N.size()/2;i++)
        {
            N[N.size()-1-i]=N[i];
        }
        return N;        
        
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
}  // } Driver Code Ends
