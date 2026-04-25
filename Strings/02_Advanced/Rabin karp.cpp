#include <iostream>
#include <vector>
using namespace std;
vector<int> search(string s,string p){
    int d=256;
    int q=101;
    int n=s.length();
    int m=p.length();
    vector<int>ans;
    int hash=0;
    int text=0;
    int h=1;
     for (int i = 0; i < m - 1; i++)h = (h * d) % q;
    for(int i =0;i<m;i++){
        hash=(hash*d+int(p[i]))%q;
        text=(text*d+int(s[i]))%q;
    }
    for(int i=0;i<=n-m;i++){
        if(hash==text){
            bool match=true;
         for(int j=0;j<m;j++){
             if(p[j]!=s[i+j]){
                 match=false;
                 break;
             }
         }
         if(match)ans.push_back(i);
        }
        if(i < n - m){
            text= (d * (text - s[i] * h) + s[i + m]) % q;
            if(text < 0) text += q;
        }
        
    }
    
    return ans;
}
int main() {
 string s="geeksofgeeks";
 string p="geeks";
 vector<int>result=search(s,p);
 for(int i =0;i<result.size();i++){
     cout<<result[i]<<' ';
 }

    return 0;
}
