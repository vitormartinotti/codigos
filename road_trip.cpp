//CSES ROAD TRIP
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;

vector<int> grafo[MAXN];
vector<int> path;

int marc[MAXN], pai[MAXN], primeiro, segundo;

bool dfs(int v, int p) {
    marc[v] = 1;
    for(auto viz : grafo[v]){
        if(marc[viz] == 0){
            pai[viz] = v;
            if(dfs(viz, v)){
                return true;
            }
        }
        else if(viz != p){ //Encontrou um ciclo
            primeiro = viz; //Vértice onde fechou o ciclo: primeiro vértice do caminho
            segundo = v; //Pai do vértice: próximo vértice do caminho, onde os pais até o vértice do ciclo são o caminho
            return true;
        }
    }
    return false;
}

int main(){
    int n, m; scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++){
        int a, b; scanf("%d %d", &a, &b);
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    int i = 1;
    while(i <= n){
        if(marc[i] == 0){
            if(dfs(i,-1)){
                break;
            }
        }
        i++;
    }

    if(i == n+1){
        printf("IMPOSSIBLE");
        return 0;
    }

    //Recuperando o caminho
    path.push_back(primeiro);
    path.push_back(segundo);
    while(pai[segundo] != primeiro){
        path.push_back(pai[segundo]);
        segundo = pai[segundo];
    }
    path.push_back(pai[segundo]);


    printf("%d\n", path.size());
    for(auto e : path){
        printf("%d ", e);
    }
}
