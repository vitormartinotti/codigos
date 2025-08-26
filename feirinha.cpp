//OBI 2025 PJ F2

#include<bits/stdc++.h>
#define MAXN 100010

using namespace std;

int tipo[MAXN];
vector<int> preco_t1;
vector<int> preco_t2;

int main(){
    int n; scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        scanf("%d", &tipo[i]);
    }

    for(int i = 1; i <= n; i++){
        int p; scanf("%d", &p);
        if(tipo[i] == 1) preco_t1.push_back(p);
        else preco_t2.push_back(p);
    }

    sort(preco_t1.begin(), preco_t1.end());
    sort(preco_t2.begin(), preco_t2.end());

    int p1 = 0, p2 = 0;

    int c; scanf("%d", &c);
    int resp = 0;
    for(int i = 1; i <= c; i++){
        int u; scanf("%d", &u);
        //indeciso
        if(u == 0){
            if(p1 == preco_t1.size() && p2 == preco_t2.size()) continue;
            if(p1 == preco_t1.size()){
                resp += preco_t2[p2];
                p2++;
            }
            else if(p2 == preco_t2.size()){
                resp += preco_t1[p1];
                p1++;
            }
            else{
                if(preco_t1[p1] <= preco_t2[p2]){
                    resp += preco_t1[p1];
                    p1++;
                }
                else{
                    resp += preco_t2[p2];
                    p2++;
                }
            }
        }
        //decidido
        else{
            if(u == 1){
                if(p1 == preco_t1.size()) continue;
                resp += preco_t1[p1];
                p1++;
            }
            else{
                if(p2 == preco_t2.size()) continue;
                resp += preco_t2[p2];
                p2++;
            }
        }
    }

    printf("%d", resp);
}
