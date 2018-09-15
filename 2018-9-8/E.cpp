#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;
// head
const int N = 1e5+5;

int a[N];

int main() {
  int n, t;
  scanf("%d", &t);
  for (int cas = 1; cas <= t; cas++) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    int l = 0, cur = 0;
    int ans = -2e9, ans_l, ans_r;
    for (int i = 0; i < n; i++) {
      if (cur >= 0) {
        cur += a[i];
      } else {
        cur = a[i], l = i;
      }
      if (cur > ans) {
        tie(ans, ans_l, ans_r) = make_tuple(cur, l, i);
      }
    }
    printf("Case %d:\n", cas);
    printf("%d %d %d\n", ans, ans_l + 1, ans_r + 1);
    if (cas < t) puts("");
  }
  return 0;
}
