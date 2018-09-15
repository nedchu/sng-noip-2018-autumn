/*************************************************************************
    > File Name: F.cpp
    > Author: wennitao
    > Mail: wennitao@126.com 
    > Created Time: Áù  9/ 8 23:43:53 2018
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f ;
struct seg {
	int l, r, id ;
	bool operator < (const seg &a) const {
		if (l == a.l) return r < a.r ;
		return l > a.l ;
	}
}s[510] ;
int dp[510], pre[510], tmp[510] ;
bool cmp (int a, int b) {
	return s[a].r - s[a].l < s[b].r - s[b].l ;
}
int main()
{
	int n ;
	cin >> n ;
	for (int i = 1; i <= n; i ++) {
		scanf ("%d%d", &s[i].l, &s[i].r) ;
		s[i].id = i ;
	}
	sort (s + 1, s + n + 1) ;
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j < i; j ++)
			if (s[i].l < s[j].l && s[i].r > s[j].r)
				if (dp[j] + 1 > dp[i]) {
					dp[i] = dp[j] + 1 ;
					pre[i] = j ;
				}
		if (!dp[i]) dp[i] = 1 ;
	}
	int ans = 0, x, tot = 0 ;
    for (int i = 1; i <= n; i ++)
		if (dp[i] > ans)
			ans = dp[i], x = i ;
	printf("%d\n", ans) ;
	while (x) {
		tmp[++ tot] = s[x].id ;
		x = pre[x] ;
	}
	for (int i = tot; i >= 1; i --)
		printf("%d ", tmp[i]) ;
	printf("\n") ;
	return 0 ;
}