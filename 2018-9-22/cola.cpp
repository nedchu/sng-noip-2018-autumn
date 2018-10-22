#include <bits/stdc++.h>
using namespace std;
#define N 110
struct node
{
    int y, z;
    node(){}
    node(int y, int z) : y(y), z(z){}
};
queue <node> Q;
int a[3], b[3], c[3], dp[6][3] = {
    -1, 0, 1,
    -1, 1, 0,
    1, -1, 0,
    0, -1, 1,
    1, 0, -1,
    0, 1, -1
};
bool vis[N][N];
int dis[N][N];
void pour(int cupa, int cupb, int &wa, int &wb) {
    int t = min(cupb, wa + wb);
    wa = wa + wb - t;
    wb = t;
}
void bfs(int x, int y, int z) {
    vis[y][z] = true;
    while(!Q.empty()) Q.pop();
    Q.push(node(y, z));
    while(!Q.empty()) {
        node ft = Q.front();
        Q.pop();
        b[1] = ft.y;
        b[2] = ft.z;
        b[0] = a[0] - b[1] - b[2];
        for(int k = 0;k < 6;k++) {
            memcpy(c, b, sizeof(b));
            int s, t;
            for(int i = 0;i < 3;i++) {
                if(dp[k][i] == 1)
                    s = i;
                if(dp[k][i] == -1)
                    t = i;
            }
            pour(a[s], a[t], c[s], c[t]);
            if(vis[c[1]][c[2]])
                continue;
            vis[c[1]][c[2]] = true;
            dis[c[1]][c[2]] = dis[b[1]][b[2]] + 1;
            if(c[0]*2 == c[0]+c[1]+c[2] && (max(c[1],c[2])*2 == c[0]+c[1]+c[2])) {
                cout << dis[c[1]][c[2]] << endl;
                return;
            }
            Q.push(node(c[1], c[2]));
        }
    }
    cout << "NO\n";
}
int main() {
    while(cin >> a[0] >> a[1] >> a[2]) {
        if(!a[0] && !a[1] && !a[2])
            break;
        memset(vis, false, sizeof(vis));
        memset(dis, 0, sizeof(dis));
        if(a[0] & 1)
            printf("NO\n");
        else 
            bfs(a[0], 0, 0);
    }
    return 0;
}