//Construct Quad Tree

class Solution {
public:
    int sum(int r1, int c1, int r2, int c2, vector<vector<int>> &presum) {
        return presum[r2+1][c2+1] - presum[r1][c2+1] - presum[r2+1][c1] + presum[r1][c1];
    }

    int val(int r1, int c1, int r2, int c2, vector<vector<int>> &presum) {
        int total = sum(r1, c1, r2, c2, presum);
        int area = (r2 - r1 + 1)*(c2 - c1 + 1);

        if(total == 0) return 0;
        if(total == area) return 1;
        return -1;
    }
    
    Node* construct(int r1, int c1, int r2, int c2, vector<vector<int>> &presum) {
        int value = val(r1, c1, r2, c2, presum);
        
        if(value != -1) {
            return new Node(value, true);
        }
        
        int side = (r2 - r1 + 1) / 2;

        return new Node(false, false,
            construct(r1, c1, r2 - side, c2 - side, presum), 
            construct(r1, c1 + side, r2 - side, c2, presum), 
            construct(r1 + side, c1, r2, c2 - side, presum), 
            construct(r1 + side, c1 + side, r2, c2, presum) // bottomRight
        );
    }

    Node* construct(vector<vector<int>>& grid) {
        int len = grid.size();

        vector<vector<int>> calc(len+1,vector<int>(len+1,0));

        for(int i = 0; i< len; i++){
            for(int j= 0; j< len;j++){
              calc[i+1][j+1] = grid[i][j]+calc[i][j+1]+calc[i+1][j]- calc[i][j];
            }
        }

        return construct(0, 0, len - 1, len - 1, calc);
    }
};
