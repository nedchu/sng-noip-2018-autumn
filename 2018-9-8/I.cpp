/*************************************************************************
    > File Name: I.cpp
    > Author: wennitao
    > Mail: wennitao@126.com 
    > Created Time: »’  9/ 9 14:27:56 2018
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
bool ok[710][710], dp[710][710][2] ;
int a[710] ;
int gcd (int a, int b) {
	return b ? gcd (b, a % b) : a ;
}
int main()
{
	int n ;
	cin >> n ;
	for (int i = 1; i <= n; i ++)
		scanf("%d", &a[i]) ;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			if (gcd (a[i], a[j]) != 1)
				ok[i][j] = 1 ;
	for (int i = 1; i <= n; i ++) ok[0][i] = ok[i][n + 1] = 1 ;
	for (int i = 0; i <= n; i ++) dp[i + 1][i][0] = dp[i + 1][i][1] = 1 ;
	for (int i = 1; i <= n; i ++) {
		dp[i][i][0] = ok[i - 1][i] ;
		dp[i][i][1] = ok[i][i + 1] ;
	}
	for (int len = 2; len <= n; len ++)
		for (int l = 1; l <= n - len + 1; l ++) {
			int r = l + len - 1 ;
			for (int k = l; k <= r; k ++) {
				if (dp[l][k - 1][1] && dp[k + 1][r][0]) {
					if (ok[l - 1][k]) dp[l][r][0] = 1 ;
					if (ok[k][r + 1]) dp[l][r][1] = 1 ;
				}
			}
		}
    if (dp[1][n][0]) printf("Yes\n") ;
	else printf("No\n") ;
	return 0 ;
}