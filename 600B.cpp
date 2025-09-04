#include<bits/stdc++.h>
#define MAXN 100010

using namespace std;

int v[MAXN];

int main() {
    int n, k; scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    for(int i = 0; i < k; i++){
        int q; scanf("%d", &q);
        int pos = lower_bound(v, v+n, q)-v;
        printf("%d ", pos+1);
    }
}
