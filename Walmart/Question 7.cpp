//Sorted subsequence of size 3


class Solution{
  public:
    vector<int> find3Numbers(vector<int> arr, int N) {
        // Your code here
        vector<int>res;
         vector<int>leftArr(N);
        leftArr[0] = arr[0];
        vector<int>rightArr(N);
        rightArr[N-1] = arr[N-1];
        for(int i = 1;i < N;i++){
            leftArr[i] = min(leftArr[i-1],arr[i]);
        }
        
        for(int i = N-2;i >= 0;i--){
            rightArr[i] = max(rightArr[i+1],arr[i]);
        }
        for(int i = 0; i < N;i++){
            if(leftArr[i] < arr[i] && arr[i] < rightArr[i]){
                res.push_back(leftArr[i]);
                res.push_back(arr[i]);
                res.push_back(rightArr[i]);
                break;
            }
        }
        return res;
    }
};

