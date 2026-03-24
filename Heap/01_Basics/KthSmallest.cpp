// Time: O(n log k) | Space: O(k)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int arr[8]={10,20,-4,6,28,24,105,118};
    //using maxheap for for finding kth smallest and using minheap for finding kth largest number
    int k=4;
    priority_queue<int>pq;
    int n= sizeof(arr)/sizeof(arr[0]);
    for(int i =0;i<n;i++){
        pq.push(arr[i]);
        if(pq.size()>k)pq.pop();
    }
    cout<<pq.top();
   

    return 0;
}
