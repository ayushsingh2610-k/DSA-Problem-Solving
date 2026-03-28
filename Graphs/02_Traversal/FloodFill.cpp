// Time: O(m*n) | Space: O(m*n)
class Solution {
public:
 void dfs(vector<vector<int>>&img,int currrow,int currcol,int initialcolor,int color){
          int r= img.size();
          int c= img[0].size();
          if(currrow>=r||currcol>=c||currrow<0||currcol<0)return ;
          if(img[currrow][currcol]!=initialcolor)return;  
          img[currrow][currcol]=color;
           dfs(img,currrow+1,currcol,initialcolor,color);
           dfs(img,currrow-1,currcol,initialcolor,color);
           dfs(img,currrow,currcol+1,initialcolor,color);
           dfs(img,currrow,currcol-1,initialcolor,color);

        }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color ==image[sr][sc])return image;
        dfs(image,sr,sc,image[sr][sc],color);
        return image ;
    }
   
};
