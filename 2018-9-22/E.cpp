#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define N 110
#define M 110
int mp[N][M];
bool vis[N][M];
struct node
{
    int x, y;
    node(){}
    node(int x, int y) : x(x), y(y){}
};
queue <node> Q;
int n = 8, m = 8, K, dp[8][2] = {
    1, 2, -1, -2, 2, 1, -2, -1,
    1, -2, -1, 2, 2, -1, -2, 1,
};
void print() {
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            printf("%d%c", mp[i][j], " \n"[j==m-1]);
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
        for(int k = 0;k < 8;k++) {
            int tx = x + dp[k][0], ty = y + dp[k][1];
            if(tx < 0 || tx >= n || ty < 0 || ty >= m || vis[tx][ty])
                continue;
            vis[tx][ty] = true;
            mp[tx][ty] = mp[x][y] + 1;
            if(tx == u && ty == v)
                return mp[tx][ty];
            Q.push(node(tx, ty));
        }
        // print();
    }
}
int main() {
    char s1[3], s2[3];
    while(cin >> s1 >> s2) {
        memset(mp, 0, sizeof(mp));
        memset(vis, false, sizeof(vis)); 
        cout << "To get from " << s1 << " to " << s2 << " takes " 
        << bfs(s1[0]-'a', s1[1]-'1', s2[0]-'a', s2[1]-'1') << " knight moves." << endl;
    }
    return 0;
}