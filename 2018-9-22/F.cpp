#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int n, k, ans;
char str[3][150];
bool mp[3][150];
bool pass(int x, int y) {
    for(int j = 1;j < 4;j++) {
        if(y+j >= n)
            return true;
        if(str[x][y+j] != '.') 
            return false;
    }
    return true;
}
bool dfs(int x, int y) {
    mp[x][y] = true;
    if(str[x][y+1] != '.')      
        return false;
    for(int i = 0;i < 3;i++) {
        if(abs(i-x) > 1 || !pass(i, y)) continue;
        if(y+3 >= n-1 || (!mp[i][y+3] && dfs(i, y+3)))
            return true;
    }
    return false;
}
int main() {
    int T;
    cin >> T;
    while(T--) {
        cin >> n >> k;
        for(int i = 0;i < 3;i++)
            cin >> str[i];
        memset(mp, false, sizeof(mp));
        for(int i = 0;i < 3;i++) {
            if(str[i][0] == 's') {
                cout << (dfs(i, 0) ? "YES" : "NO") << endl;
                break;
            }
        }
    }
    return 0;
}