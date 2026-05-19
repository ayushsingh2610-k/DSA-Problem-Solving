class Solution {
public:
bool check(int k,vector<int>& a,int m){
    int p=1;
    int curr=0;
    for(int x:a){
        if(curr+x<=m)curr+=x;
        else{
            p++;
            curr=x;
        }
    }
    return p<=k;

}
    int splitArray(vector<int>& nums, int k) {
    int n =nums.size();
    int mx=INT_MIN;
    int sum=0;
    for(int i =0;i<n;i++){
        mx=max(mx,nums[i]);
        sum+=nums[i];
    }
    
    int lo=mx;
    int hi =sum;
    int ans=hi;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(check(k,nums,mid)){
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
