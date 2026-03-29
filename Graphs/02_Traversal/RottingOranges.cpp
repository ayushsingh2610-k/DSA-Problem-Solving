class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r= grid.size();
        int c= grid[0].size();
        queue<pair<int,int>>q;
        int fresh=0;
        for(int i =0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==2){q.push({i,j});}
                else if(grid[i][j]==1)fresh++;
            }
        }
        int distance=0;
        while(q.size()!=0 && fresh>0){
        int size = q.size();
         for(int k = 0; k < size; k++){
         auto x=q.front();
         int i =x.first;
         int j= x.second;
         q.pop();
         if(i+1<r && grid[i+1][j]==1){
            fresh--;
            grid[i+1][j]=0;
            q.push({i+1,j});
         }
          if(i-1>=0 && grid[i-1][j]==1){
            grid[i-1][j]=0;
            q.push({i-1,j});
            fresh--;
         }
          if(j+1<c && grid[i][j+1]==1){
            grid[i][j+1]=0;
            q.push({i,j+1});
            fresh--;
         }
          if(j-1>=0 && grid[i][j-1]==1){
            grid[i][j-1]=0;
            q.push({i,j-1});
            fresh--;
         }}
         distance++;
        }
       
        if(fresh>0)return -1;
        else return distance;
    }
};
