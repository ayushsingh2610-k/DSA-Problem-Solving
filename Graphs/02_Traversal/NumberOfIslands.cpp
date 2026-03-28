class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
     int rows= grid.size();
     int columns=grid[0].size();
     int cc=0;
     for(int i =0;i<rows;i++){
     for(int j =0;j<columns;j++){
        if(grid[i][j]=='0')continue;
        cc++;
        grid[i][j]='0';
        queue<pair<int,int>>q;
        q.push({i,j});
        while(q.size()!=0){
            auto curr=q.front();
            int r= curr.first;
            int c= curr.second;
            q.pop();
            if(r-1>=0 && grid[r-1][c]=='1'){
                q.push({r-1,c});
                grid[r-1][c]='0';
            }
            if(r+1<rows && grid[r+1][c]=='1'){
                q.push({r+1,c});
                grid[r+1][c]='0';
            }
            if(c-1>=0 && grid[r][c-1]=='1'){
                q.push({r,c-1});
                grid[r][c-1]='0';
            }
            if(c+1<columns && grid[r][c+1]=='1'){
                q.push({r,c+1});
                grid[r][c+1]='0';
            }
            
        }
        }
     }
     return cc;   
    }
};
