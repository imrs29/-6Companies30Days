//Course Schedule II

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
            
            
        unordered_map<int,vector<int>> m;
        vector<int> dg(numCourses,0);   
        
        for(int i=0; i<prerequisites.size(); i++)
        {
            m[prerequisites[i][1]].push_back(prerequisites[i][0]);
            dg[prerequisites[i][0]]++;
        }
        
        vector<int> res;
        queue<int> q;
        
        for(int i=0; i<numCourses; i++)
            if(dg[i] == 0)
            {
                q.push(i);
                res.push_back(i);
            }
                
        
        while(!q.empty())
        {
            int parent = q.front();
            q.pop();
            
            for(int i=0; i<m[parent].size(); i++)
            {
                int child = m[parent][i];
                dg[child]--;
                
                if(dg[child] == 0)
                {
                    q.push(child);
                    res.push_back(child);
                }
            }
        }
        
        for(int i=0; i<numCourses; i++)
        {
            if(dg[i] > 0)      
            {
                res.clear();
                break;
            }
        }
        return res;
    }
        
    
};
