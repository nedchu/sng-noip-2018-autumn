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
bool dfs(int k, int n) {
    if(k == n) {
        print(n);
        for(int i = 0;i < n;i++) 
            printf("%d ", queen[i]+1);
        printf("\n");
        return true;
    }
    for(int i = 0;i < n;i++) if(check(k, i)) {
        queen[k] = i;
        if(dfs(k+1, n))
            return true;
    }
    return false;
}
int main() {
    int n;
    while(cin >> n, n) {
        dfs(0, n);
    }
    return 0;
}