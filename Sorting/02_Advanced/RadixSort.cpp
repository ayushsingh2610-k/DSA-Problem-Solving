#include <iostream>
#include <vector>
#include <climits>
using namespace std;
void countsort(vector<int>& arr,int exp){
    int n =arr.size();
    vector<int>output(n);
    int count[10]={0};
    for(int i =0;i<n;i++){
        count[(arr[i]/exp)%10]++;
    }
    for(int i =1;i<10;i++){
        count[i]+=count[i-1];
    }
    for(int i =n-1;i>=0;i--){
        int d=(arr[i]/exp)%10;
        output[count[d]-1]=arr[i];
        count[d]--;
    }
    for(int i =0;i<output.size();i++){
        arr[i]=output[i];
    }
}
void radixsort(vector<int>& arr){
    int mx=INT_MIN;
    int n= arr.size();
    for(int i=0;i<n;i++){
        mx=max(mx,arr[i]);
    }
    for(int i =1;mx/i>0;i*=10){
        countsort(arr,i);
    }
    
}
int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    radixsort(arr);
    for(int i =0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
