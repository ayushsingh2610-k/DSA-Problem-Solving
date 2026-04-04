#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void bucketsort(float arr[],int n ){
    vector<float>bucket[n];
for(int i=0;i<n;i++){
    int idx=n*arr[i];
    bucket[idx].push_back(arr[i]);
}
for(int i =0;i<n;i++){
    sort(bucket[i].begin(),bucket[i].end());
}
int k=0;
for(int i =0;i<n;i++){
    for(auto x: bucket[i]){
        arr[k++]=x;
    }
}
   
}
int main(){
     float arr[] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47};
     int n = sizeof(arr)/sizeof(arr[0]);
     bucketsort(arr,n);
     for(int i  =0;i<n;i++){
         cout<<arr[i]<< " ";
     }
    
}
