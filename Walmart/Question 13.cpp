// Find the Kth Largest Integer in the Array (Cows and Farm Question)

class Solution {
public:
    
    static bool comparator(string str1, string str2){
      if(str1.size() > str2.size())
          return false;
        if(str2.size() > str1.size())
            return true;
        for(int i = 0; i < str1.size(); i++){
            if(str1[i] > str2[i])
                return false;
            if(str2[i] > str1[i])
                return true;
            
        }
        return false;
    }
    
    
    
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), comparator);
        return nums[nums.size() - k];
    }
};
