# 2018-9-15 深度优先搜索&广度优先搜索

## 信息
作业：[link](https://vjudge.net/contest/255650)

作业基础要求：至少完成 4 题

作业进阶要求：尝试使用搜索完成所有问题


## 复习搜索

[N 皇后](https://vjudge.net/problem/HDU-2553)

将 N 个皇后放在 N * N 的棋盘上，互相不侵犯（不在同行、同列、同45度斜线上）。问有多少种摆法。

![](http://poj.org/images/3239_1.png)

> 将什么作为一种状态？

若将放置着棋子的棋盘( N * N )作为状态，则要储存的状态较大，状态转移要做的判断比较多。  
由于皇后在不同列，记第 i 列的皇后在第 queen[i] 个位置，则一个一维数组即可表示出一种棋盘的状态。  
如上图可以表示为queen[] = {2,4,6,8,3,1,7,5}  
则问题转化为 N 个整数的排列问题，但约束条件更多一些。

```cpp
bool check(int x, int y) {
    for(int i = 0;i < x;i++)
        if(queen[i] == y || queen[i]-i == y-x || queen[i]+i == y+x)
            return false;
    return true;
}
void dfs(int k, int n) {
    if(k == n) {
        cnt++;
        return;
    }
    for(int i = 0;i < n;i++) if(check(k, i)) {
        queen[k] = i;
        dfs(k+1, n);
    }
}

```
延伸：N 的范围到 300 时，求一种构造棋盘的方案。[link](http://poj.org/problem?id=3239&lang=zh-CN)
## 什么是深度优先搜索/广度优先搜索

如果把某一时刻的棋盘看作一个状态，则刚才我们采用了深度优先搜索。

![](https://tse2.mm.bing.net/th?id=OIP.YEqe2UUJCY5_GE_RJIoFPQHaGW&pid=Api)

### DFS (Depth First Search)

![](http://res.jisuanke.com/img/upload/20160115/6f34a3d3d3f0244226bcf57837a2be5b8aef6e52.gif)

### BFS (Breadth First Search)
![](http://res.jisuanke.com/img/upload/20160115/f0b929a7d2796b4fc2bb2740bab51d42c096f963.gif)

### 栈和队列的类比

访问节点时，需要保留一系列的节点以备后用，用什么样的数据结构来存？

对于 DFS 而言，后访问的节点先读取（后进先出），用栈来存。  
对于 BFS 而言，先访问的节点先读取（先进先出），用队列来存。  

由于函数的调用调用了系统堆栈，因此 DFS 时并不需要显式地定义栈，调用子函数时已经完成了栈的功能。

## 棋盘类上的搜索

要抽象出点和边。

前面的例子，一个时刻的棋盘是点，若一时刻能转移到下一时刻则可以建边。

更为普遍的情况是，将格点作为点，格点之间若是相邻则建边。

## 连通块

相邻有**四连通**（上下左右）和**八连通**（上下左右和对角）两种情况，后者包含了前者。

[八连通统计连通块数目](https://vjudge.net/problem/HDU-1241)


```cpp
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
void dfs(int x, int y) {
    vis[x][y] = true;
    
    int tx = x + 1, ty = y + 0;
    if(!(tx < 0 || tx >= n || ty < 0 || ty >= m || vis[tx][ty] || mp[tx][ty] == '*'))
        dfs(tx, ty);

    tx = x - 1, ty = y + 0;
    ...
    tx = x + 0, ty = y + 1;
    ...
    tx = x + 0, ty = y - 1;
    ...
    tx = x + 1, ty = y + 1;
    ...
    tx = x + 1, ty = y - 1;
    ...
    tx = x - 1, ty = y + 1;
    ...
    tx = x - 1, ty = y - 1;
    ...
    
}
```

由于有大量重复的代码块，可以将坐标的改变量，即**方向向量**，作为二维数组保存下来。先判断是否在棋盘上，再考虑是否访问过，若满足一定条件，才开始 DFS.

```cpp
int dp[8][2] = {
    1, 0, -1, 0, 0, 1, 0, -1,
    1, 1, -1, -1, 1, -1, -1, 1
};
void dfs(int x, int y) {
    vis[x][y] = true;
    for(int k = 0;k < 8;k++) {
        int tx = x + dp[k][0], ty = y + dp[k][1];
        if(tx < 0 || tx >= n || ty < 0 || ty >= m || vis[tx][ty] || mp[tx][ty] == '*')
            continue;
        dfs(tx, ty);
    }
}
```

如果是简单地标记棋盘，不需要返回值。当需要返回值时，考虑程序何时终止返回。

[算连通块面积](https://vjudge.net/problem/POJ-3620)
```cpp
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
```

关于连通块也可以用 BFS 进行遍历，从源点开始一层一层往外扩张。

### 求最短路径

单一的 DFS 无法满足搜到终点时，所经过的路径为最短路。将每条路径逐一比较又费时费力。此时可以考虑用 BFS 的方式，层层扩张，当一个结点在第 i 层时，它到源点的距离就是 i ，除此之外，不可能找到更短的路径。

![](https://tse3.mm.bing.net/th?id=OIP.4HduGeCCisT-MNZ-m25L7AHaFs&pid=Api)

[跳马求最短路](https://vjudge.net/problem/HDU-1372)

```cpp
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
    }
}
```
### 回溯

求出最短路的路径或是单纯地求路径。增加一个靠谱的数组 parent 来记录到这个点是用了哪个方向向量，减去这个向量就是它的上一级节点了。

[迷宫求最短路径](https://vjudge.net/problem/POJ-3984)

```cpp
int mp[N][M], dis[N][M], parent[N][M];
bool vis[N][M];

dfs/bfs:
{
    vis[tx][ty] = true;
    dis[tx][ty] = dis[x][y] + 1;
    parent[tx][ty] = k;
}

void print_path(int x, int y) {
    int k = parent[x][y];
    if(x || y)
        print_path(x - dp[k][0], y - dp[k][1]);
    printf("(%d, %d)\n", x, y);
}
```

### 小结：棋盘问题需要注意的问题

**我WA故我在……**  

- 状态转移OK吗？
    - 方向数组检查
- 初始化了吗？
    - 棋盘清空，访问标记清空。  
- 访问越界了吗？  
    - 判断下一步在棋盘上  
- 剪枝了吗？  
    - 满足一定条件才需要继续 DFS  
- 死循环了吗？
    - 要标记访问数组
- 及时终止返回了吗？  
    - 有时只需找到一个解

***
## 非棋盘类问题
要抽象出问题的状态和转移关系，有时并不会在题中显式地给出。

[倒水](https://vjudge.net/problem/HDU-1495)

三个杯子中的水为 x, y, z，则三元组 (x, y, z) 可以认为是一个状态。可以有 6 种倒水的方式，到达下一状态。

```cpp
void pour(int cupa, int cupb, int &wa, int &wb) {
    int t = min(cupb, wa + wb);
    wa = wa + wb - t;
    wb = t;
}
bool vis[N][N/2][N/2];
int dis[N][N/2][N/2];
void bfs(int x, int y, int z) {
    vis[x][y][z] = true;
    while(!Q.empty()) Q.pop();
    Q.push(node(x, y, z));
    while(!Q.empty()) {
        node ft = Q.front();
        Q.pop();
        b[0] = ft.x;
        b[1] = ft.y;
        b[2] = ft.z;
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
            if(vis[c[0]][c[1]][c[2]])
                continue;
            vis[c[0]][c[1]][c[2]] = true;
            dis[c[0]][c[1]][c[2]] = dis[b[0]][b[1]][b[2]] + 1;
            if(c[0]*2 == c[0]+c[1]+c[2] && (max(c[1],c[2])*2 == c[0]+c[1]+c[2])) {
                cout << dis[c[0]][c[1]][c[2]] << endl;
                return;
            }
            Q.push(node(c[0], c[1], c[2]));
        }
    }
    cout << "NO\n";
}
```

其中三维的状态可以缩减到二维。因为从两个杯子的水量，可以知道第三个杯子的水量。

```cpp
bool vis[N][N/2][N/2]; -> vis[N/2][N/2]
int dis[N][N/2][N/2]; -> dis[N/2][N/2]
---------------------------------------------
Runtime Error
(ACCESS_VIOLATION)
```

## 练习

[N 皇后](https://vjudge.net/problem/HDU-2553)

[八连通统计连通块数目](https://vjudge.net/problem/HDU-1241)

[算连通块面积](https://vjudge.net/problem/POJ-3620)

[四连通环](https://vjudge.net/problem/CodeForces-510B)  

[数独](https://vjudge.net/problem/POJ-2676)

[穿越火车](https://vjudge.net/problem/CodeForces-586D)

[迷宫求最短路径](https://vjudge.net/problem/POJ-3984)

[中途取物](https://vjudge.net/problem/POJ-3170)

[数字跳跃](https://vjudge.net/problem/POJ-3278)

[素数跳跃](https://vjudge.net/problem/POJ-3126)