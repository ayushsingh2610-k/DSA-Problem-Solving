#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int>& v,int si,int ei){
    int pielement=v[(si+ei)/2];
    int count=0;
    for(int i =si;i<=ei;i++){
        if(i==(si+ei)/2)continue;
        if(pielement>=v[i]){
                count++;}
    }
            int pivotidx=count+si;
            swap(v[(si+ei)/2],v[pivotidx]);
            int i=si;
            int j=ei;
            while(i<pivotidx && j>pivotidx){
                if(v[i]<=pielement)i++;
                else if(v[j]>pielement)j--;
                else if(v[i]>pielement && v[j]<=pielement){
                    swap(v[i],v[j]);
                    i++;
                    j--;
                }
            }
            return pivotidx;
}
int quicksort(vector<int>& v,int si,int ei ,int k){
    int pi=partition(v,si,ei);
    if(pi==k)return v[pi];
    else if(pi<k)return quicksort(v,pi+1,ei,k);
    else return quicksort(v,si,pi-1,k);
}
int main() {
    int n;
    cin>>n;
    int k;
    cin>>k;
    k=k-1;
    vector<int>v(n);
    for(int i =0;i<n;i++){
        cin>>v[i];
    }
   cout<<quicksort(v,0,n-1,k);
    for(int i =0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
