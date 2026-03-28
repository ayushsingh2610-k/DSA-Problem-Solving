class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n =isConnected.size();
        int count=0;
        vector<int>visited(n,0);
        for(int i =0;i<n;i++){
            if(visited[i]==1)continue;
            count++;
            queue<int>q;
            visited[i]=1;
            q.push(i);
            while(q.size()!=0){
                int x= q.front();
                q.pop();
                visited[x]=1;
              for(int j =0;j<n;j++){
                if(isConnected[x][j]==1 && visited[j] == 0){
                    q.push(j);
                    visited[j]=1;
                }
              }
            }
        }
        return count;
    }
};
