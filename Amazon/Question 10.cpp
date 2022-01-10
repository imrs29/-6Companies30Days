// Rotting Oranges

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        if(grid.empty()) 
            return 0;
        int row = grid.size(), col = grid[0].size(), days = 0, tot = 0, count = 0;
        queue<pair<int, int>>rotting;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
            if(grid[i][j] != 0)
                tot++;
            if(grid[i][j] == 2)
                rotting.push({i,j});
        }
    }
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    while(!rotting.empty()){
        int k = rotting.size();
        count += k;
        while(k--){
            int x = rotting.front().first, y = rotting.front().second;
            rotting.pop();
            for(int i=0;i<4;i++){
                int nx = x+dx[i], ny = y+dy[i];
                if(nx < 0 || ny < 0 || nx >= row || ny >= col || grid[nx][ny] != 1)
                    continue;
                grid[nx][ny]=2;
                rotting.push({nx,ny});
                
            }
        }
        if(!rotting.empty())
            days++;
    }
    return tot ==count?days:-1;
}
};
