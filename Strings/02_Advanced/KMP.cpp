#include <iostream>
#include<vector>
using namespace std;
int main() {
    string s="abcdaabceaabceaabdop";
    string p="aabceaabdo";
    //lps
    int n=p.length();
    vector<int>lps(n,0);
    int i =0;
    int j=1;
    while(j<n){
        if(p[i]==p[j]){
            lps[j]=i+1;
            i++;
            j++;
        }
        else{
            if(i==0){
                lps[j]=0;
                j++;
            }
            else{
                i=lps[i-1];
            }
        }
    }
    //string matching
    int k=0;
    int z=0;
    while(k<s.length() && z<p.length()){
        if(s[k]==p[z]){
            k++;
            z++;
        }
        else{
            if(z==0){
                k++;
            }
            else{
                z=lps[z-1];
            }
        }
    }
    if(z==p.length()){
     cout<< "matched";
    }

    return 0;
}
