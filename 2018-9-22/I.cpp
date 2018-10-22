#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
bool isPrime[10000];
bool vis[10000];
int dis[10000];
queue <int> Q;
void init() {
    memset(isPrime, true, sizeof(isPrime));
    for(int i = 1000;i < 10000;i++)
        for(int j = 2;j < sqrt(i)+2;j++)
            if(i % j == 0)
                isPrime[i] = false;
}
void bfs(int a, int b) {
    if(a == b) {
        cout << 0 << endl;
        return;
    }
    while(!Q.empty()) Q.pop();
    Q.push(a);
    vis[a] = true;
    dis[a] = 0;
    while(!Q.empty()) {
        a = Q.front();
        Q.pop();
        int dig = 1, num;
        for(int i = 0;i < 4;i++) {    
            dig *= 10;
            num = a % dig / (dig/10);
            for(int k = 0;k < 10;k++) {
                if(k == num || (i==3&&k==0)) continue;
                int t = a - num*dig/10 + k*dig/10;
                if(!isPrime[t] || vis[t]) continue;
                vis[t] = true;
                dis[t] = dis[a] + 1;
                if(t == b) {
                    cout << dis[t] << endl;
                    return;
                }
                Q.push(t);
            }
        }
    }
    cout << "Impossible" << endl;
}
int main() {
    init();
    int T, a, b;
    cin >> T;
    while(T--) {
        cin >> a >> b;
        memset(vis, false, sizeof(vis));
        memset(dis, 0, sizeof(dis));
        bfs(a, b);
    }
    return 0;
}