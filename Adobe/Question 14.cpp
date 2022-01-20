//Smallest range in K lists

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
          //code here
          priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>q;
          
          int minE = INT_MAX, maxE = INT_MIN, range = INT_MAX;
          int left = 0, right = 0;
          for(int i = 0; i < k; i++){
              q.push({KSortedArray[i][0],{i,0}});
              minE = min(KSortedArray[i][0], minE);
               maxE = max(KSortedArray[i][0], maxE);
              
          }
          while(true){
              pair<int, pair<int,int>> temp = q.top();
              q.pop();
              
              int mn = temp.first;
              if(range > maxE - mn){
                  minE = mn;
                  left = minE;
                  right = maxE;
                  range = maxE-minE;
              }
              
              int i = temp.second.first;
              int j = temp.second.second;
              
              if(j == n-1)
              break;
              
              q.push({KSortedArray[i][j+1],{i,j+1}});
              if(maxE < KSortedArray[i][j+1]){
                  maxE = KSortedArray[i][j+1];
              }
          }
          return {left, right};
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

  // } Driver Code Ends
