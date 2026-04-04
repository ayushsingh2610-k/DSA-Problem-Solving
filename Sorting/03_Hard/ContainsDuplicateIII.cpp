class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff){
        int n=nums.size();
    unordered_map<long long ,long long>bucket;
       long long bucketsize=valueDiff+1;
       for(int i =0;i<n;i++){
        int id=nums[i]/bucketsize;
        if(nums[i]<0)id--;
        if(bucket.count(id))return true;
        if(bucket.count(id-1) && abs(bucket[id-1]-nums[i])<=valueDiff)return true;
        if(bucket.count(id+1) && abs(bucket[id+1]-nums[i])<=valueDiff)return true;
        bucket[id]=nums[i];
        if(i>=indexDiff){
            long long  old=nums[i-indexDiff];
            long long oldid=old/bucketsize;
            if(old<0)oldid--;
            bucket.erase(oldid);
        }
       }
         return false;
} };
