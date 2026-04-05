class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m= nums2.size();
        vector<double>v;
        int i=0;
        int j=0;
        while(i<n && j<m){
            if(nums1[i]>=nums2[j]){
                v.push_back(nums2[j]);
                j++;
            }
            else{
                v.push_back(nums1[i]);
                i++;
            }
        }
        while(i<n){
            v.push_back(nums1[i]);
            i++;
        }
        while(j<m){
            v.push_back(nums2[j]);
            j++;
        }
        double s=0;
        if((m+n)%2==0){
            s=(v[(m+n)/2]+v[(m+n-2)/2])/2;
        }
        else{
            s=v[(m+n)/2];
        }
        return s;
        
    }
};
