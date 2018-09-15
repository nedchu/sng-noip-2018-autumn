/*************************************************************************
    > File Name: B.cpp
    > Author: wennitao
    > Mail: wennitao@126.com 
    > Created Time: Áù  9/ 8 18:21:37 2018
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int dp[1010][1010] ;
char a[1010], b[1010] ;
int main()
{
	while (scanf("%s%s", a, b) != EOF) {
		memset (dp, 0, sizeof dp) ;
		int n = strlen(a), m = strlen(b) ;
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= m; j ++) {
				if (a[i - 1] == b[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1 ;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) ;
			}
		printf("%d\n", dp[n][m]) ;
	}
    return 0 ;
}