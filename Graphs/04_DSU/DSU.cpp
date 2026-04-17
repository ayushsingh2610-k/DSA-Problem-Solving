#include <iostream>
#include <vector>
using namespace std;

int find(int x, vector<int>& parent){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x], parent); // path compression
}

void unite(vector<int>& parent, vector<int>& rank, int a, int b){
    int pa = find(a, parent);
    int pb = find(b, parent);

    if(pa == pb) return;

    if(rank[pa] < rank[pb]){
        parent[pa] = pb;
    }
    else if(rank[pa] > rank[pb]){
        parent[pb] = pa;
    }
    else{
        parent[pb] = pa;
        rank[pa]++;
    }
}

int main(){
    int n = 5; // example
    vector<int> parent(n);
    vector<int> rank(n, 0);

    for(int i = 0; i < n; i++){
        parent[i] = i;
    }

    unite(parent, rank, 0, 1);
    unite(parent, rank, 1, 2);

    cout << find(2, parent) << endl;

    return 0;
}
