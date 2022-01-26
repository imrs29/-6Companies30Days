//Find the missing no in string

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_DIGITS = 5;

int missingNumber(const string& str);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        cout << missingNumber(str)<<endl;
    }
	return 0;
}
// } Driver Code Ends


/* You are required to complete this function
which return the required missing number
if present else return -1*/
int missingNumber(const string& str)
{
    // Code here
    int res;
    int len = str.size();
    for(int i = 1; i <= min(len,6); i++)
    {
        bool flag=1;
        int n;
        string st;
        st = str.substr(0,i);
       
        n = stoi(st);
        n++;
        st = to_string(n);
      
        int j=i;
        bool found=0;
        while(j<str.size())
        {
            string value = str.substr(j,st.size());
            
            if(value != st)
            {
                st = to_string(++n);
                if(str.size()-j+1<st.size()) 
                {
                    flag=0; 
                    break;
                    
                }
                value = str.substr(j,st.size());
                if(value!=st||found)
                {
                    flag=false; 
                    break;
                    
                }
                res=n-1;
                found=1;
            }
            
            n++;
            j += st.size();
            st = to_string(n);
        }
       
       if(flag && found)
       return res;
       
    }
    return -1;
}
