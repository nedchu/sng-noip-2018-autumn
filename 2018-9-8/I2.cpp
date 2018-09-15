#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;
// head
const int N = 705;

int a[N];
bool ok[N][N];
bool l[N][N], r[N][N];


int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    memset(l, 0, sizeof l);
    memset(r, 0, sizeof r);
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        ok[i][j] = ok[j][i] = __gcd(a[i], a[j]) > 1;
      }
    }
    for (int i = 0; i < n; i++) {
      l[i][0] = r[i][0] = true;
    }
    for (int len = 1; len < n; len++) {
      for (int i = 0; i + len < n; i++) {
        for (int j = i+1; j <= i + len; j++) {
          if (ok[i][j]) {
            r[i][len] |= l[j][j-i-1] && r[j][i+len-j];
          }
        }
      }
      for (int i = len; i < n; i++) {
        for (int j = i - len; j < i; j++) {
          if (ok[i][j]) {
            l[i][len] |= l[j][j-i+len] && r[j][i-j-1];
          }
        }
      }
    }
    bool ans = false;
    for (int i = 0; i < n; i++) {
      ans |= l[i][i] && r[i][n-i-1];
    }
    puts(ans ? "Yes" : "No");
  }
  return 0;
}
