class Solution {
  public:
  void merge(vector<int>& a, vector<int>& b,vector<int>& v){
      int n = a.size();
      int m= b.size();
        int i=0;
        int j=0;
        int k=0;
        while(i<n && j<m){
            if(a[i]>=b[j]){
                v[k]=(b[j]);
                j++;
                k++;
            }
            else{
                v[k]=(a[i]);
                i++;
                k++;
            }
        }
        while(i<n){
            v[k]=(a[i]);
            i++;
            k++;
            
        }
        while(j<m){
            v[k]=(b[j]);
            j++;
            k++;
        }
  }
  int inversion(vector<int>& a,vector<int>& b){
      int count=0;
      int i=0;
      int j=0;
      while(i<a.size()&& j<b.size()){
          if(a[i]>b[j]){
              count+=a.size()-i;
              j++;
          }
          else{
              i++;
              
          }
      }
      return count;
  }
  void mergesort(vector<int>& arr,int &count){
      int  n=arr.size();
      if(n==1)return;
      int n1=arr.size()/2;
      int n2=arr.size()-arr.size()/2;
      vector<int>a(n1);
      vector<int>b(n2);
      for(int i =0;i<n1;i++){
          a[i]=arr[i];
          
      }
      for(int i=0;i<n2;i++){
          b[i]=arr[n1+i];
      }
      mergesort(a,count);
      mergesort(b,count);
      count+=inversion(a,b);
      merge(a,b,arr);
  }
  
    int inversionCount(vector<int> &arr) {
        int count;
        mergesort(arr,count);
        return count;
    }
};
