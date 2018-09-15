/*************************************************************************
    > File Name: H.cpp
    > Author: wennitao
    > Mail: wennitao@126.com 
    > Created Time: »’  9/ 9 00:34:06 2018
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll a[510][510], sum[510][510] ;
int main()
{
	int n, m ;
	scanf("%d%d", &m, &n) ;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			scanf("%lld", &a[i][j]) ;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			sum[i][j] += sum[i][j - 1] + a[i][j] ;
	ll ans = -INF ;
	for (int i = 1; i <= m; i ++)
		for (int j = i; j <= m; j ++) {
			ll mn = 0, s = 0 ;
			for (int k = 1; k <= n; k ++) {
				s += sum[k][j] - sum[k][i - 1] ;
				ans = max (ans, s - mn) ;
				mn = min (mn, s) ;
			}
		}
	if (ans < 0) printf("0\n") ;
	else printf("%lld\n", ans) ;
  return 0 ;
}