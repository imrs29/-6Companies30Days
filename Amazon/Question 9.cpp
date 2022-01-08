// Is Sudoku Valid

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

bool isrange(vector<vector<int>> m)
{
    for(int i=0;i<m.size();i++)
    {
        for(int j=0;j<m.size();j++)
        {
            if(m[i][j]<0 || m[i][j]>9)
            {
                return false;
            }
        }
    }
    return true;
}
    int isValid(vector<vector<int>> mat){
        // code here
        
         if(isrange(mat)==false)
        {
            return false;
        }
        int n=mat.size();
        bool unique[n+1];
        for(int i=0;i<n;i++)
        {
            memset(unique, false,
                   sizeof(unique));
            for(int j=0;j<n;j++)
            {
                int z=mat[i][j];
               if(z!=0)
                {
                    if(unique[z])
                    {
                        return false;
                    }
                    unique[z]=true;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
           memset(unique, false,
                   sizeof(unique));
            for(int j=0;j<n;j++)
            {
                int z=mat[j][i];
                
                if(z!=0)
                {
                    if(unique[z])
                    {
                        return false;
                    }
                    unique[z]=true;
                }
            }
        }
        for(int i=0;i<n-2;i+=3)
        {
            for(int j=0;j<n-2;j+=3)
            {
                memset(unique, false,
                   sizeof(unique));
                
                for(int k=0;k<3;k++)
                {
                    for(int l=0;l<3;l++)
                    {
                        int x=i+k;
                        int y=j+l;
                        
                        int z=mat[x][y];
                        
                        if(z!=0)
                        {
                            if(unique[z])
                            {
                                return false;
                            }
                            unique[z]=true;
                        }
                    }
                }
            }
        }
        return true;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
