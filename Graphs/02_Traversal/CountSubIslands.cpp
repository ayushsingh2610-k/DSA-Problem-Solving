class Solution {
public:
bool match(vector<vector<int>>& g1,vector<vector<int>>& g2,int sr,int sc){
int r=g1.size();
bool flag=true;
int c=g1[0].size();
queue<pair<int,int>>q;
q.push({sr,sc});
        if(g1[sr][sc] == 0) flag = false;
        g2[sr][sc] = 0;


  while(q.size()!=0){
    auto x=q.front();
    q.pop();
     int f=x.first;
     int s=x.second;
     if(f+1<r && g2[f+1][s]==1){
        if(g1[f+1][s]==0)flag=false;
        g1[f+1][s]=0;
        g2[f+1][s]=0;
        q.push({f+1,s});

     }
      if(f-1>=0 && g2[f-1][s]==1){
        if(g1[f-1][s]==0)flag=false;
        g1[f-1][s]=0;
        g2[f-1][s]=0;
        q.push({f-1,s});

     }
      if(s+1<c && g2[f][s+1]==1){
        if(g1[f][s+1]==0)flag=false;
        g1[f][s+1]=0;
        g2[f][s+1]=0;
        q.push({f,s+1});

     }
      if(s-1>=0 && g2[f][s-1]==1){
        if(g1[f][s-1]==0)flag=false;
        g1[f][s-1]=0;
        g2[f][s-1]=0;
        q.push({f,s-1});

     }
  }
  return flag;
}
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int r=grid1.size();
        int c= grid1[0].size();
        int count=0;
        for(int i =0;i<r;i++){
            for(int j =0;j<c;j++){
            if(grid2[i][j]==0)continue;
            else if (match(grid1,grid2,i,j))count++;
            }
        }
        return count;
    }
};
