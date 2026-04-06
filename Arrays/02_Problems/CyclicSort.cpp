#include <iostream>
#include <vector>
using namespace std;
int main() {
   int n;
   cin>>n;
   vector<int>v(n);
   for(int i =0;i<n;i++){
       cin>>v[i];
   }
   int i =0;
   while(i<n){
       int correctidx=v[i]-1;
       if(i==correctidx)i++;
       else{
           swap(v[i],v[correctidx]);
       }
   }
   for(int i =0;i<n;i++){
       cout<<v[i]<<" ";
   }

    return 0;
}
