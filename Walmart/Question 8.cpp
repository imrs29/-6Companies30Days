// Maximum height tree

class Solution{
public:
    int height(int N){
        // code here
        int i, sum = 0;
        for(i = 1; sum <= N; i++){
            sum += i;
        }
        return i-2;
    }
    
};
