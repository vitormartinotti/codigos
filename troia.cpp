#include <bits/stdc++.h>
#define MAXN 500010

using namespace std;

vector<int> grafo[MAXN];
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

int main() {
	
	int n, m; scanf("%d %d", &n, &m);
	
	for(int i = 0; i < m; i++){
		int a, b; scanf("%d %d", &a, &b);
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}
	
	int nComp = 0; //o numero de familias eh igual ao numero de componentes
	for(int v = 1; v <= n; v++){
		if(marc[v] == 0){
			nComp++; //conta uma componente
			dfs(v);
		}
	}
	
	printf("%d\n", nComp);

	return 0;
}
