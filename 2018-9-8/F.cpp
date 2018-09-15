#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;
// head
const int N = 505;

pii a[N];
int b[N], bk[N], dp[N];

int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &a[i].fi, &a[i].se);
      b[i] = i;
    }
    sort(b, b + n, [](int x, int y) {
      return a[x].se - a[x].fi < a[y].se - a[y].fi;
    });

    fill(dp, dp + n, 1);
    fill(bk, bk + n, -1);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        pii x = a[b[i]], y = a[b[j]];
        if (x.fi < y.fi && x.se > y.se && dp[j] + 1 > dp[i]) {
          dp[i] = dp[j] + 1;
          bk[i] = j;
        }
      }
    }

    int cur = max_element(dp, dp + n) - dp;
    int ans = dp[cur];
    vector<int> res;
    while (cur != -1) {
      res.push_back(b[cur] + 1);
      cur = bk[cur];
    }
    reverse(all(res));
    printf("%d\n", ans);
    for (int i = 0; i < res.size(); i++) {
      printf("%d%c", res[i], i==res.size()-1 ? '\n' : ' ');
    }
  }
  return 0;
}