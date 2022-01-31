//Maximum Performance of a Team

class Solution {
public:
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        vector<pair<int,int>> v;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < n; i++){
            v.push_back({efficiency[i], speed[i]});
        }
        
        long long total = 0, res = 0;
        sort(v.begin(), v.end());
        for(auto i = n-1; i >= 0; i--){
            
            total += v[i].second;
            pq.push(v[i].second);
            if(pq.size() > k){
                total -= pq.top();
                pq.pop();
            }
            
            res = max(res, total * v[i].first);
        }
        return res % 1000000007;
    }
};
