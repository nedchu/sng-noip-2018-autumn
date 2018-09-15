#include <bits/stdc++.h>

using namespace std;

const int N = 5e5+5;

int dp[N];
int a[N];

int main() {
  int cas = 1;
  int n, u, v;
  while (scanf("%d", &n) == 1) {
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &u, &v);
      u--, v--;
      a[u] = v;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int pos = lower_bound(dp, dp + ans, a[i]) - dp;
      dp[pos] = a[i];
      if (pos == ans) ans++;
    }
    printf("Case %d:\n", cas++);
    if (ans == 1) {
      printf("My king, at most 1 road can be built.\n\n");
    } else {
      printf("My king, at most %d roads can be built.\n\n", ans);
    }
  }
  return 0;
}