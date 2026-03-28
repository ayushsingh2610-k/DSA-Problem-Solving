#include <iostream>
#include <vector>
#include<list>
#include<unordered_map>
using namespace std;
vector<unordered_map<int,int>>graph;
int v;
void add_edge(int src,int dest ,int wt,bool bidirec=true){
    graph[src][dest]=wt;
    if(bidirec){
        graph[dest][src]=wt;
    }
}
void display(){
    for(int i =0;i<graph.size();i++){
        cout<<i<<"->";
        for(auto el :graph[i]){
            cout<<el.first<< ' '<<el.second;
                }
    }
    
}

int main() {
    cin>>v;
    graph.resize(v,unordered_map<int,int>());
    int e;
    cin>>e;
    while(e--){
        int s,d,wt;
        cin>>s>>d>>wt;
        add_edge(s,d,wt,false);
    }
    display();

    return 0;
}
