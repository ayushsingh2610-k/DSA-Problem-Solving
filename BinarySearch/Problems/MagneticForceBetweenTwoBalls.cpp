class Solution {
public:
bool check(vector<int>& p,int m,int mid){
    int n=p.size();
    int count=1;
    int a=p[0];
    for(int i =0;i<n;i++){
        if(p[i]-a>=mid){
            count++;
            a=p[i];
            if(count>=m)return true;
        }
    }
    return false;
}
    int maxDistance(vector<int>& position, int m) {
    sort(position.begin(),position.end());
    int lo=1;
    int hi=position.back()-position.front();
    int ans;
    while(lo<=hi){
 int mid=lo+(hi-lo)/2;
  if(check(position,m,mid)){
  ans=mid;
  lo=mid+1;
  }
  else{
    hi=mid-1;
  }

    }
    return ans;
    }
};
