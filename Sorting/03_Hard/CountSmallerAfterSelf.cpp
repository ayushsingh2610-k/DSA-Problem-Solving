class Solution {
public:

    void merge(vector<pair<int,int>>& a, vector<pair<int,int>>& b, vector<pair<int,int>>& v, vector<int>& result){
        int n = a.size();
        int m = b.size();
        int i = 0, j = 0, k = 0;
        int rightCount = 0;

        while(i < n && j < m){
            if(a[i].first <= b[j].first){
                result[a[i].second] += rightCount; 
                v[k++] = a[i++];
            }
            else{
                rightCount++; 
                v[k++] = b[j++];
            }
        }

        while(i < n){
            result[a[i].second] += rightCount;
            v[k++] = a[i++];
        }

        while(j < m){
            v[k++] = b[j++];
        }
    }

    void mergesort(vector<pair<int,int>>& arr , vector<int>& result){
        int n = arr.size();
        if(n <= 1) return;

        int mid = n / 2;

        vector<pair<int,int>> a(arr.begin(), arr.begin() + mid);
        vector<pair<int,int>> b(arr.begin() + mid, arr.end());

        mergesort(a, result);
        mergesort(b, result);

        merge(a, b, arr, result); 
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> arr;
        vector<int> result(n, 0);

        for(int i = 0; i < n; i++){
            arr.push_back({nums[i], i});
        }

        mergesort(arr, result);
        return result;
    }
};
