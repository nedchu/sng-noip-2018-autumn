#include <bits/stdc++.h>
using namespace std;
#define N 110
#define M 110
int n, m, dp[8][2] = {
    1, 0, -1, 0, 0, 1, 0, -1,
    1, 1, -1, -1, 1, -1, -1, 1
};
char mp[N][M];
bool vis[N][M];
void dfs(int x, int y) {
    vis[x][y] = true;
    for(int k = 0;k < 8;k++) {
        int tx = x + dp[k][0], ty = y + dp[k][1];
        if(tx < 0 || tx >= n || ty < 0 || ty >= m || vis[tx][ty] || mp[tx][ty] == '*')
            continue;
        dfs(tx, ty);
    }
}
int work() {
    int res = 0;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            if(!vis[i][j] && mp[i][j] == '@') {
                dfs(i, j);
                res++;
            }
    return res;
}
int main() {
    while(cin >> n >> m, n, m) {
        for(int i = 0;i < n;i++)
            cin >> mp[i];
        memset(vis, false, sizeof(vis)); 
        cout << work() << endl;
    }
    return 0;
}