/*************************************************************************
    > File Name: A.cpp
    > Author: wennitao
    > Mail: wennitao@126.com 
    > Created Time: Áù  9/ 8 18:17:06 2018
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int dp[1010] ;
int val[1010], w[1010] ;
int main()
{
	int T ;
	cin >> T ;
	while (T --) {
		memset (dp, 0, sizeof dp) ;
		int n, v ;
		scanf("%d%d", &n, &v) ;
		for (int i = 1; i <= n; i ++)
			scanf("%d", &val[i]) ;
		for (int i = 1; i <= n; i ++)
			scanf("%d", &w[i]) ;
		for (int i = 1; i <= n; i ++)
			for (int j = v; j >= w[i]; j --)
				dp[j] = max(dp[j], dp[j - w[i]] + val[i]) ;
		printf("%d\n", dp[v]) ;
	}
    return 0 ;
}