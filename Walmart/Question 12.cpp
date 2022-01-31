// Find Array Given Subset Sums

class Solution {
public:
       vector<int> recoverArray(int n, vector<int>& sums) {
           
            sort(sums.begin(),sums.end());
            return helper(n,sums);
    }
    
    vector<int> helper(int n, vector<int>& sums){
        
        
        bool zero = false;
        for(int num:sums){
        
            if(num==0){
                zero = true;
            }
        }
        
        if(!zero){
            return {};
        }
        
        if(n==1){
            return {sums[0]+sums[1]};
        }
        int len = sums.size();
        for(int ii=1;ii<=len/2;ii++){
            int i =ii;
            int diff = sums[i] - sums[0];
            
            vector<int> next;
            vector<int> taken(len,0);
            next.push_back(sums[0]);
            taken[i] = 1;
            i++;
            for(int j=1;j<len;j++){
                if(taken[j]){
                    continue;
                }
                i = max(i,j+1);
                
                while(sums[i]-sums[j]<diff&&i<len){
                    i++;
                }
                if(i==len||sums[i]-sums[j]>diff){
                    break;
                }
                
                taken[i] = 1;
                i++;
                next.push_back(sums[j]);
            }
           
            if(next.size()!=len/2){
                continue;
            }
            auto vec = helper(n-1,next);
            if(!vec.empty()){
                vec.push_back(diff);
                return vec;
            }
            
            for(int &num:next){
                num += diff;
            }
            auto vec2 = helper(n-1,next);
            if(!vec2.empty()){
                vec2.push_back(-diff);
                return vec2;
            }            

        }
        
        return {};
    }
};
