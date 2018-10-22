#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;
#define N 110
#define M 110
int mp[N][M], dis[N][M], parent[N][M];
bool vis[N][M];
struct node
{
    int x, y;
    node(){}
    node(int x, int y) : x(x), y(y){}
};
queue <node> Q;
int n = 8, m = 8, K, dp[8][2] = {
    1, 0, -1, 0, 0, 1, 0, -1
};
void print() {
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            printf("%d%c", dis[i][j], " \n"[j==m-1]);
    printf("===\n");
}
int bfs(int x, int y, int u, int v) {
    if(x == u && y == v)
        return 0;
    while(!Q.empty()) Q.pop();
    Q.push(node(x, y));
    vis[x][y] = true;
    while(!Q.empty()) {
        node ft = Q.front();
        Q.pop();
        x = ft.x;
        y = ft.y;
        for(int k = 0;k < 4;k++) {
            int tx = x + dp[k][0], ty = y + dp[k][1];
            if(tx < 0 || tx >= n || ty < 0 || ty >= m || vis[tx][ty] || mp[tx][ty] == 1)
                continue;
            vis[tx][ty] = true;
            dis[tx][ty] = dis[x][y] + 1;
            parent[tx][ty] = k;
            if(tx == u && ty == v)
                return dis[tx][ty];
            Q.push(node(tx, ty));
        }
        // print();
    }
}
void print_path(int x, int y) {
    int k = parent[x][y];
    if(x || y)
        print_path(x - dp[k][0], y - dp[k][1]);
    printf("(%d, %d)\n", x, y);
}
int main() {
    n = m = 5;
    for(int i = 0;i < n;i++) 
        for(int j = 0;j < m;j++)
            cin >> mp[i][j];
    memset(vis, 0, sizeof(vis));
    memset(parent, 0, sizeof(parent));
    memset(dis, 0, sizeof(dis));
    bfs(0, 0, n-1, m-1);
    print_path(n-1, m-1);
    return 0;
}