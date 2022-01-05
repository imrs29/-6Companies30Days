//Minimum Size Subarray Sum

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minSum = 0;
        int ct = 0;
        int minLength = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            int j = i;
            while(minSum < target && j < nums.size()){
                 minSum += nums[j++];
                 ct++;
                 if(minSum >= target){
                     minLength = min(minLength, ct);
                     ct = 0;
                 }
            }
            minSum=0;
        }
        if(minLength == INT_MAX){
            return 0;
        }else{
            return minLength;
        }
        
        
    }
};
