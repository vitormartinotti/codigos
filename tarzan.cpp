#include <bits/stdc++.h>
#define MAXN 50010

using namespace std;

vector<int> grafo[MAXN];
vector<pair<int,int>> arvores;
int marc[MAXN];

void dfs(int v){
    marc[v] = 1;
    for(int i = 0; i < grafo[v].size(); i++){
        int viz = grafo[v][i];
        if(marc[viz] == 0){
            dfs(viz);
        }
    }
}

int main(){
    int n, d; scanf("%d %d", &n, &d);

    for(int i = 0; i < n; i++){
        int x, y; scanf("%d %d", &x, &y);
        arvores.push_back({x,y});
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j){
                int x1 = arvores[i].first;
                int x2 = arvores[j].first;
                int y1 = arvores[i].second;
                int y2 = arvores[j].second;
                if(d*d <= (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)){
                    grafo[i].push_back(j);
                    grafo[j].push_back(i);
                }
            }
        }
    }

    int resp = 0;
    for(int i = 0; i <= n-1; i++){
        if(marc[i] == 0){
            resp++;
            dfs(i);
        }
    }

    if(resp == 1){
        printf("S");
    }
    else{
        printf("N");
    }
}
