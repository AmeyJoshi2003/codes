#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;

class solution{
    
    public:
    
    vector<int> dijikistra(int V,vector<vector<int>> adj[],int S){
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        vector<int>distV(V,INT_MAX);
        
        
        distV[S]=0;
        pq.push({0,S});
        
        while(!pq.empty()){
            int node=pq.top().second;
            int dist=pq.top().first;
            pq.pop();
            
            for(auto it:adj[node]){
                int v=it[0];
                int w=it[1];
                
                if(dist+w<distV[v]){
                    distV[v]=dist+w;
                    
                    pq.push({dist+w,v});
                }
            }
        }
        return distV;
    }
};

int main(){
    int V=3,E=3,S=2;
    vector<vector<int>>adj[V];
    vector<int> v1{1, 1}, v2{2, 6}, v3{2, 3}, v4{0, 1}, v5{1, 3}, v6{0, 6};
    int i=0;
    
    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);
    
    solution obj;
    vector<int>res= obj.dijikistra(V,adj,S);
    
    for(int i=0;i<V;i++){
        cout<<res[i]<<" ";
    }
    
    return 0;
}