// Possible Words From Phone Digits

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
      unordered_map<int,vector<char>>mp;
   public:
   //Function to find list of all words possible by pressing given numbers.
   Solution(){
       mp[2]={'a','b','c'};
       mp[3]={'d','e','f'};
       mp[4]={'g','h','i'};
       mp[5]={'j','k','l'};
       mp[6]={'m','n','o'};
       mp[7]={'p','q','r','s'};
       mp[8]={'t','u','v'};
       mp[9]={'w','x','y','z'};
   }
   
   void check(int i,int a[],int n,vector<string>&ans,string str){
       if(i == n){
           ans.push_back(str);
           return ;
       }
       
       for(int j=0;j<mp[a[i]].size();j++){
           check(i+1 , a, n, ans, str+mp[a[i]][j]);
       }
       
   }
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
         vector<string>ans;
         string str="";
         check(0,a,N,ans,str);
         return ans;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends
