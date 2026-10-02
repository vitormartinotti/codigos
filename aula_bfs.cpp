#include<bits/stdc++.h>

using namespace std;

vector<int> grafo[MAXN];

int marc[MAXN], dist[MAXN];

void bfs(int s){
    queue<int> q;
    q.push(s);
    marc[s] = 1;
    dist[s] = 0;
    pai[s] = -1;

    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto viz : grafo[v]){
            if(marc[viz] == 0){
                q.push(viz);
                marc[viz] = 1;
                dist[viz] = dist[v]+1;
                pai[viz] = v;
            }
        }
    }
}

int main(){
    
    //recuperando o menor caminho do n até a fonte
    vector<int> path;
    while(pai[n] != -1){
        path.push_back(n);
        n = pai[n];
    }
    path.push_back(n);
    reverse(path.begin(),path.end());
    
}
