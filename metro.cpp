#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;

vector<int> grafo[MAXN];

int marc[MAXN], grau[MAXN], removido[MAXN], pai[MAXN];

void dfs(int v) {
    marc[v] = 1;
    for(auto viz : grafo[v]){
        if(marc[viz] == 0){
            pai[viz] = v;
            dfs(viz);
        }
    }
}

int main(){
    int n, m; scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++){
        int a, b; scanf("%d %d", &a, &b);
        grafo[a].push_back(b); grau[a]++; //Insere o vizinho e aumenta o grau
        grafo[b].push_back(a); grau[b]++;
    }

    //O centro é o vértice de maior grau
    int centro = 0;
    int na_linha = 0;
    for(int i = 1; i <= n; i++){
        if(grau[i] > grau[centro]){
            centro = i;
        }
        if(grau[i] == 3){ //Encontra algum vértice na linha circular
            na_linha = i;
        }
    }

    dfs(na_linha); //Estabelece o vetor pai[n] a partir de um vértice na linha circular

    //Marca o centro como removido e diminui o grau dos seus vizinhos
    removido[centro] = 1;
    for(auto viz : grafo[centro]){
        grau[viz]--;
    }

    //Cada "ponta solta" começa por um vértice de grau 1 e termina em um vértice de grau 3
    //Ao remover um vértice, o próximo vértice da "ponta solta" (prox) terá grau um
    for(int i = 1; i <= n; i++){
        if(grau[i] == 1){
            removido[i] = 1;
            int prox = pai[i];
            grau[prox]--;
            while(grau[prox] == 1){
                removido[prox] = 1;
                prox = pai[prox];
            }
        }
    }

    int resp = 0;
    for(int i = 1; i <= n; i++){
        if(removido[i] == 0){
            resp++;
        }
    }

    printf("%d", resp);
}
