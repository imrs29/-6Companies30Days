// Run Length Encoding

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  //Your code here 
  string str;
  int ct = 1;
  char c = src[0];
  for(int i=1;i<src.length();i++){
      if(src[i] == c)
      ct++;
      else{
          str = str + c + to_string(ct);
          ct=1;
          c=src[i];
      }
  }
  str = str + c + to_string(ct);
  return str;
}     
 
