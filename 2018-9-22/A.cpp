#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
#define N 110
#define M 110
char mp[N][M];
bool vis[N][M];
int n, m, K, dp[4][2] = {
    1, 0, -1, 0, 0, 1, 0, -1
};
int dfs(int x, int y) {
    int area = 1;
    vis[x][y] = true;
    for(int k = 0;k < 4;k++) {
        int tx = x + dp[k][0], ty = y + dp[k][1];
        if(tx < 0 || tx >= n || ty < 0 || ty >= m || vis[tx][ty])
            continue;
        if(mp[tx][ty])
            area += dfs(tx, ty);
    }
    return area;
}
int work() {
    int res = 0;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            if(!vis[i][j] && mp[i][j])
                res = max(res, dfs(i, j));
    return res;
}
int main() {
    while(cin >> n >> m >> K) {
        memset(mp, false, sizeof(mp));
        memset(vis, false, sizeof(vis)); 
        for(int i = 0;i < K;i++) {
            int u, v;
            cin >> u >> v;
            mp[u-1][v-1] = true;
        }
        cout << work() << endl;
    }
    return 0;
}