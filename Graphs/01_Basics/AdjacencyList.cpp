#include <iostream>
#include <vector>
#include<list>
using namespace std;
vector<list<int>>graph;
int v;
void add_edge(int src,int dest,bool bidirec=true){
    graph[src].push_back(dest);
    if(bidirec){
        graph[dest].push_back(src);
    }
}
void display(){
    for(int i =0;i<graph.size();i++){
        cout<<i<<"->";
        for(auto el :graph[i]){
            cout<<el<< ' ';
                }
    }
    
}

int main() {
    cin>>v;
    graph.resize(v,list<int>());
    int e;
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d,false);//true for bidirectional
    }
    display();

    return 0;
}
