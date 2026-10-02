#include<bits/stdc++.h>
#define MAXN 100010
#define ll long long

using namespace std;

int N, M, K;
vector<pair<ll,int>> grafo[MAXN]; //grafo[u][i] = (w,v) u-w->v
int tem_recarga[MAXN];

// Função de verificação: checa se é possível ir de 1 até N com capacidade C
bool dijkstra(ll C) {
    // dist[u] guarda a maior energia restante com a qual chegamos na cidade u
    vector<ll> dist(N+1, -1);
    
    set<pair<ll, int>> s; //pair<energia_restante, cidade>
    
    dist[1] = C;
    s.insert({C, 1});
    
    while (!s.empty()) {
        int v = s.rbegin()->second; //cidade
        ll energia_atual = s.rbegin()->first; //energia atual
        s.erase(prev(s.end()));
        
        if (v == N) return true; // Se chegamos na cidade N, o teste foi bem sucedido

        // Se já encontramos um caminho que chega em 'v' com energia maior, ignoramos
        if (energia_atual < dist[v]) continue;
        
        // Se a cidade 'v' é uma estação de recarga, restauramos a energia para C
        if (tem_recarga[v] == 1) {
            energia_atual = C;
            dist[v] = C;
        }
        
        // Explora todas as rodovias conectadas à cidade 'u'
        for (auto e : grafo[v]) {
            int viz = e.second;
            ll custo = e.first;
            
            // Só atravessamos se a bateria atual for suficiente
            if (energia_atual >= custo) {
                ll proxima_energia;
                if (tem_recarga[viz] == 1) {
                    proxima_energia = C;
                }
                else{
                    proxima_energia = energia_atual - custo;
                }
                if (proxima_energia > dist[viz]) { //Relaxa o caminho para viz
                    dist[viz] = proxima_energia;
                    s.insert({proxima_energia, viz});
                }
            }
        }
    }
    
    return false; // Não foi possível alcançar a cidade N
}

int main() {
    
    scanf("%d %d", &N, &M);
    
    // Leitura do grafo
    for (int i = 1; i <= M; i++) {
        int v, u;
        ll c;
        scanf("%d %d %lld", &v, &u, &c);
        grafo[v].push_back({c, u});
        grafo[u].push_back({c, v});
    }
    
    // Leitura das estações de recarga
    scanf("%d", &K);
    for (int i = 1; i <= K; i++) {
        int x;
        scanf("%d", &x);
        tem_recarga[x] = 1;
    }
    
    // Busca Binária no valor da capacidade C
    ll inicio = 1, fim = 1e15;
    ll resposta = fim;
    
    while (inicio <= fim){
        ll meio = (inicio + fim)/2;
        
        if (dijkstra(meio)){
            resposta = meio;   // A capacidade 'meio' funciona, tentamos um valor menor
            fim = meio - 1;
        } 
        else{
            inicio = meio + 1; // Capacidade insuficiente, precisamos aumentar
        }
    }
    
    printf("%lld", resposta);
    
    return 0;
}
