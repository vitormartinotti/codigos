#include<bits/stdc++.h>
#define MAXN 100
#define pii pair<int,int>
 
const int INF = 1e9+10;
 
using namespace std;
 
vector<pii> grafo[MAXN];
vector<int> dist(MAXN, INF); //dist[i]: menor distância de s até i
int pai[MAXN];
 
void dijkstra(int s){
    set<pii> q;
    q.insert({0,s});
    dist[s] = 0;
 
    while(!q.empty()){
        int v = q.begin()->second;
        q.erase(q.begin());
        for(int i = 0; i < grafo[v].size(); i++){
            pii viz = grafo[v][i];
            int u = viz.second;
            int w = viz.first;
            if(dist[v]+w < dist[u]){
                pai[u] = v;
                q.erase({dist[u], u});
                q.insert({dist[v]+w, u});
                dist[u] = dist[v]+w;
            }
        }
    }
}
 
int main(){
    int n, m; scanf("%d %d", &n, &m);
 
    while(m--){
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        grafo[a].push_back({c,b});
        //grafo[b].push_back({c,a});
    }
 
    for(int i = 0; i < n; i++){
        pai[i] = i;
    }
    
    dijkstra(0);
 
    vector<int> caminho;
    int p = n-1;
    while(pai[p] != p){
        caminho.push_back(p);
        p = pai[p];
    }
    caminho.push_back(0);
    
    for(int i = 0; i < n; i++){
        printf("%d ", dist[i]);
    }
}
