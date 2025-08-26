//Executar o programa com o teste salvo em um aquivo de texto "dados.txt"

#include<bits/stdc++.h>
#define MAXN 100010

using namespace std;

multiset<pair<int,int>> produtos;

multiset<pair<int,int>> tprodutos[MAXN];

int tipos[MAXN];
int precos[MAXN];

int main(){
    //Arquivo de teste
    FILE* arquivo = fopen("dados.txt", "r");
    if (arquivo == NULL) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return 1;
    }

    int n, t; fscanf(arquivo,"%d %d", &n, &t);

    for(int i = 1; i <= n; i++){
        fscanf(arquivo,"%d", &tipos[i]);
    }
    for(int i = 1; i <= n; i++){
        fscanf(arquivo,"%d", &precos[i]);
    }

    for(int i = 1; i <= n; i++){
        pair<int,int> p = {precos[i],tipos[i]};
        produtos.insert(p);
        tprodutos[tipos[i]].insert(p);
    }

    int c; fscanf(arquivo,"%d", &c);
    long long int resp = 0;
    for(int i = 1; i <= c; i++){
        int u; fscanf(arquivo,"%d", &u);
        if(u == 0){
            if(produtos.empty()) continue;
            pair<int,int> p = *produtos.begin();
            resp += p.first;
            produtos.erase(produtos.begin());
            tprodutos[t].erase(tprodutos[t].find(p));
        }
        else{
            if(ttipos[u].empty()) continue;
            resp += *ttipos[u].begin();
            produtos.erase(produtos.find({*ttipos[u].begin(),u}));
            ttipos[u].erase(ttipos[u].begin());
        }
    }

    printf("%lld", resp);

    return 0;
}
