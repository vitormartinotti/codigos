#include <bits/stdc++.h>
#define pii pair<int,int>
#define MAXN 100
 
const int INF = 1e9;
 
using namespace std;
 
vector<pii> grafo[MAXN];
 
int dist[MAXN];
 
void bfs01(int s){
    deque<pii> q;
    q.push_front({0,s});
    dist[s] = 0;
    while(!q.empty()){
        pii e = q.front();
        int v = e.second;
        q.pop_front();
        for(pii viz : grafo[v]){
            int u = viz.second;
            int w = viz.first;
            if(dist[v]+w < dist[u]){
                dist[u] = dist[v]+w;
                if(w == 0){
                    q.push_front(viz);
                }
                else{
                    q.push_back(viz);
                }
            }
        }
    }
}
 
int main(){
    int n, m; scanf("%d %d", &n, &m);
    
    for(int i = 0; i < m; i++){
        int a, b, c; scanf("%d %d %d", &a, &b, &c); //aresta que liga a em b com custo c
        grafo[a].push_back({c, b});
        grafo[b].push_back({c, a});
    }
    
    for(int i = 0; i <= n; i++){
        dist[i] = INF;
    }
    
    bfs01(1);
    
    printf("%d", dist[n]);
}
