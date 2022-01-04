//Find max 10 numbers in a list having 10M entries

#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    vector<long long> Max10Numbers(vector<long long> &num){
        priority_queue<long long, vector<long long>, greater<long long>>que;
        long long n = num.size();
        for(int i = 0; i < n; i++){
            que.push(num[i]);
            if(que.size() > 10)
            que.pop();
        }
        vector<long long>res(10);
        int i = 9;
        while(!que.empty()){
            res[i] = que.top();
            i--;
            que.pop();
        }
        return res;
        
    }
};

int main(){
    vector<long long>numbers = {2,40000000000,200000, 10,100,400,11,14,78,9000,1,41,43,45,56,78,90,800};
    solution s;
    vector<long long>res = s.Max10Numbers(numbers);
    for(auto &i:res)
    cout<<i<<" ";
}
