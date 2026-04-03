#include <iostream>
#include <vector>
using namespace std; 
int main() {
    int arr[]={4,2,2,8,3,3,1};
    int n=7;
    int max=arr[0];
    for(int i =1;i<n;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    //freq
    int count[max+1]={0};
    for(int i =0;i<n;i++){
        count[arr[i]]++;
    }
    //cf
    for(int i=1;i<=max;i++){
        count[i]+=count[i-1];
    }
    int ans[n];
    for(int i =n-1;i>=0;i--){
        ans[count[arr[i]]-1]=arr[i];
        count[arr[i]]--;
    }
  for(int i =0;i<n;i++){
      cout<<ans[i]<<" ";
  }

    return 0;
}
