class Solution {
public:
  
    string customSortString(string order, string s) {
  unordered_map<char,int>mp;
        int i=0;
        for(auto x:order){
            mp[x]=i;
            i++;
        }
  sort(s.begin(), s.end(), [&](char a, char b) {
            if (mp.count(a) && mp.count(b))
                return mp[a] < mp[b];

            if (mp.count(a)) return true;
            if (mp.count(b)) return false;

            return a < b; 
        });
        return s;
        
    }
};
