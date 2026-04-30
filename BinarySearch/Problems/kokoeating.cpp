class Solution {
public:
bool check(int a,vector<int>& p,int h){
 int n=p.size();
 long long m=0;
 for(int i=0;i<n;i++){
    if(p[i]%a==0)m+= p[i]/a;
    else m+=p[i]/a+1;
 }
 if(m<=h)return true;
 else return false;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int hi=INT_MIN;
        for(int i =0;i<piles.size();i++){
            hi=max(piles[i],hi);
        }
        int lo=1;
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(mid,piles,h)){
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
    return ans;
    }
};
