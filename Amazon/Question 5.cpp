// Phone Directory

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
struct Node
{
    Node* links[26];
    bool flag=false;
    Node()
    {
        for(int i=0;i<26;i++)
        links[i] = NULL;
    }
    bool containsKey(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    bool isEnd()
    {
        return flag;
    }
    void setEnd()
    {
        flag=true;
    }
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    void put(char ch,Node* node)
    {
        links[ch-'a']=node;
    }

};
class Trie{
    private: Node* root;
    public:
    Trie()
    {
        root=new Node();
    }
    void insert(string w)
    {
        Node* node = root;
        for(int i=0;i<w.size();i++)
        {
            if(!node->containsKey(w[i]))
            {
                node->put(w[i],new Node());
            }
            
            node = node->get(w[i]);
        }
        node->setEnd();
    }

    bool search(string s)
    {
        Node* node = root;
        for(int i=0;i<s.size();i++)
        {
            if(!node->containsKey(s[i]))
            {
                return false;
            }
            node = node->get(s[i]);
        }
        return (node->isEnd());

    }

    void getPrefixWords(Node* node,string prefixWord,vector<string> &prefixWords)
    {
        if(node->flag)
        {
            prefixWords.push_back(prefixWord);
        }
        
        for(char i='a';i<='z';i++)
        {
            if(node->containsKey(i))
            {
                getPrefixWords(node->get(i),prefixWord+i,prefixWords);
            }
        }
        
    }
   

    vector<vector<string>> getContacts( string contact[], string query)
    {
        // code here
        Node* node = root;
        vector<vector<string>> res;
        string prefix="";
        for(int i=0;i<query.size();i++)
        {
             prefix +=query[i];
            
            if(!node->containsKey(query[i]))
            break;
            node = node->get(query[i]);
            vector<string> prefixWords;
            getPrefixWords(node,prefix,prefixWords);
            res.push_back(prefixWords);
        }
        
        while(res.size()<query.size())
        {
            res.push_back({"0"});
        }
        return res;
    }
};

 vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        Trie* trie = new Trie();
        for(int i=0;i<n;i++)
        {
            trie->insert(contact[i]);
        }
        
        return trie->getContacts(contact,s);

    }
};


// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends
