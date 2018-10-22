#include <bits/stdc++.h>
using namespace std;
#define N 112
int queen[N], ans[N];
int cnt = 0;
void print(int n) {
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++)
            if(queen[i] == j)
                printf("+ ");
            else printf("- ");
        printf("\n");
    }
    printf("====================\n");
}
bool check(int x, int y) {
    for(int i = 0;i < x;i++)
        if(queen[i] == y || queen[i]-i == y-x || queen[i]+i == y+x)
            return false;
    return true;
}
void dfs(int k, int n) {
    if(k == n) {
        cnt++;
        // print(n);
        return;
    }
    for(int i = 0;i < n;i++) if(check(k, i)) {
        queen[k] = i;
        dfs(k+1, n);
    }
}
int main() {
    for(int i = 0;i < 10;i++) {
        cnt = 0;
        dfs(0, i+1);
        ans[i+1] = cnt;
    }
    int n;
    while(cin >> n, n) {
        cout << ans[n] << endl;
    }
    return 0;
}