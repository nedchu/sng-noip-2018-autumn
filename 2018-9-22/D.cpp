#include <cstdio>
#include <cstring>
using namespace std;
int mp[9][9];
bool row[9][10], column[9][10], group[9][10];
void update(int x, int y, int z, bool flag) {
    mp[x][y] = flag ? z : 0;
    row[x][z] = flag;
    column[y][z] = flag;
    group[x/3*3+y/3][z] = flag;
}
bool check(int x, int y, int z) {
    return row[x][z] || column[y][z] || group[x/3*3+y/3][z];
}
void print() {
    for(int i = 0;i < 9;i++) {
        for(int j = 0;j < 9;j++) 
            printf("%d", mp[i][j]);
        printf("\n");
    }
    // printf("==============\n");
}
bool dfs(int x, int y) {
    if(x == 8 && y == 9) {
        print();
        return true;
    }
    if(y == 9) {
        x++;
        y = 0;
    }
    if(mp[x][y])
        return dfs(x, y+1);
    for(int z = 1;z < 10;z++) 
        if(!check(x, y, z)) {
            update(x, y, z, true);
            // print();
            if(dfs(x, y+1))
                return true;
            update(x, y, z, false);
        }
    return false;
}
int main() {
    int n;
    char str[10];
    scanf("%d", &n);
    while(n--) {
        memset(mp, 0, sizeof(mp));
        memset(row, false, sizeof(row));
        memset(column, false, sizeof(column));
        memset(group, false, sizeof(group));
        for(int i = 0;i < 9;i++) {
            scanf("%s", str);
            for(int j = 0;j < 9;j++) {
                mp[i][j] = str[j] - '0';
                if(mp[i][j])
                    update(i, j, mp[i][j], true);
            }
        }
        dfs(0, 0);
    }
    return 0;
}