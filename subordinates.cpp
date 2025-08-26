#include<bits/stdc++.h>
#define MAX 200010
 
using namespace std;
 
vector<int> grafo[MAX];
int marc[MAX], sub[MAX], pai[MAX], nivel[MAX];
 
void dfs (int v){
    marc[v] = 1 //Nao eh necessario neste problema
    sub[v] = 1;
    for (int i = 0; i < grafo[v].size(); i++){
        int viz = grafo[v][i];
        if (marc[viz] == 0){
            pai[viz] = v; //Nao eh necessario neste problema
            nivel[viz] = nivel[v] + 1; //Nao eh necessario neste problema
            dfs(viz);
 
            sub[v] += sub[viz];
        }
    }
}
 
int main (){
    int n; scanf("%d", &n);
    for (int i = 2; i <= n; i++){
        int a; scanf("%d", &a);
        grafo[a].push_back(i);
    }
 
    dfs(1);
 
    for(int i = 1; i <= n; i++) {
        printf("%d ", sub[i]-1);
}
}
