#include <bits/stdc++.h>
using namespace std;
int n, m, dp[4][2] = {
    1, 0, -1, 0, 0, 1, 0, -1
};
char mp[55][55];
bool vis[55][55];
bool dfs(int x, int y, int fx, int fy) {
    vis[x][y] = true;
    for(int k = 0;k < 4;k++) {
        int tx = x + dp[k][0], ty = y + dp[k][1];
        if(tx < 0 || tx >= n || ty < 0 || ty >= m)
            continue;
        if(vis[tx][ty] && tx == fx && ty == fy)
            continue;
        if(vis[tx][ty] && mp[tx][ty] == mp[x][y])
            return true;
        if(!vis[tx][ty] && mp[tx][ty] == mp[x][y] && dfs(tx, ty, x, y))
            return true;
    }
    return false;
}

bool work() {
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            if(!vis[i][j] && dfs(i, j, i, j))
                return true;
    return false;
}
int main() {
    while(cin >> n >> m) {
        for(int i = 0;i < n;i++)
            cin >> mp[i];
        memset(vis, false, sizeof(vis)); // 
        if(work())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}