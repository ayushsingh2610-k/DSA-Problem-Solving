class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    int max=1000;
    vector<int>freq(max+1,0);
    for(auto x:arr1){
        freq[x]++;
    }
    vector<int>ans;
    for(auto x:arr2){
        while(freq[x]>0){
ans.push_back(x);
freq[x]--;
        }
    }
    for(int i =0;i<=max;i++){
        while(freq[i]>0){
            ans.push_back(i);
            freq[i]--;
        }
    }
return ans;
        
    }
};
