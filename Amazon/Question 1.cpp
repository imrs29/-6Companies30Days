//Longest Mountain in Array

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        int ans = 0;
        int n = arr.size();
        for(int i = 1; i < n; i++){
            int count = 1;
            bool flag = false;
            
            int j = i;
            while(j < n && arr[j] > arr[j-1]){
                j++;
                count++;
                
            }
            
            while(i != j && j < n && arr[j]<arr[j-1]){
                j++;
                count++;
                flag = true;
            }
            if(i != j && flag && count > 2){
                ans = max(ans,count);
                j--;
            }
            i=j;
        }
        return ans;
        
    }
};
