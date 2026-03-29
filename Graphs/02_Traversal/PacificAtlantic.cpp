class Solution {
public:
vector<vector<int>>grid;
vector<vector<int>>grid1;

int r,c;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
      r=heights.size();
      c=heights[0].size();
     grid.resize(r,vector<int>(c,-1));
     grid1.resize(r,vector<int>(c,-1));
     //pacific ocean
     queue<pair<int,int>>q;
     for(int i =0;i<r;i++){
      q.push({i,0});
      grid[i][0]=1;
     }
     for(int i=1;i<c;i++){
     q.push({0,i});
     grid[0][i]=1;
          }
          while(q.size()!=0){
            auto x= q.front();
            int i=x.first;
            int j=x.second;
            q.pop();
          if(i+1<r && heights[i+1][j]>=heights[i][j] && grid[i+1][j]==-1){
            grid[i+1][j]=1;
            q.push({i+1,j});
          }
          if(i-1>=0 && heights[i-1][j]>=heights[i][j] && grid[i-1][j]==-1){
            grid[i-1][j]=1;
            q.push({i-1,j});
          }
          if(j+1<c && heights[i][j+1]>=heights[i][j] && grid[i][j+1]==-1){
            grid[i][j+1]=1;
            q.push({i,j+1});
          }
          if(j-1>=0 && heights[i][j-1]>=heights[i][j] && grid[i][j-1]==-1){
            grid[i][j-1]=1;
            q.push({i,j-1});
          }
          }
          vector<vector<int>>ans;
          for(int i =0;i<c-1;i++){
      q.push({r-1,i});
      grid1[r-1][i]=2;
     }
     for(int i=0;i<r;i++){
     q.push({i,c-1});
     grid1[i][c-1]=2;
          }
           while(q.size()!=0){
            auto x= q.front();
            int i=x.first;
            int j=x.second;
            q.pop();
            if(grid[i][j]==1)ans.push_back({i,j});
          if(i+1<r && heights[i+1][j]>=heights[i][j] && grid1[i+1][j]==-1){
            grid1[i+1][j]=1;
            q.push({i+1,j});
          
          }
          if(i-1>=0 && heights[i-1][j]>=heights[i][j] && grid1[i-1][j]==-1){
            grid1[i-1][j]=1;
            q.push({i-1,j});
          }
          if(j+1<c && heights[i][j+1]>=heights[i][j] && grid1[i][j+1]==-1){
            grid1[i][j+1]=1;
            q.push({i,j+1});
          }
          if(j-1>=0 && heights[i][j-1]>=heights[i][j] && grid1[i][j-1]==-1){
            grid1[i][j-1]=1;
            q.push({i,j-1});
          }
          }
return ans;
    }
};
