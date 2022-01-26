//Number of Boomerangs

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
         int res = 0;
         unordered_map<int, int>mp;
         for(int i=0; i<points.size() ; i++){
            for(int j=0 ; j<points.size() ; j++){
                int dis = pow(points[j][1] - points[i][1], 2) + pow(points[j][0] - points[i][0], 2);
                res+= 2 * mp[dis]++;
            }
            mp.clear();
        }
        return res;    
    }
};
