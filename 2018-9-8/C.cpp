/*************************************************************************
    > File Name: C.cpp
    > Author: wennitao
    > Mail: wennitao@126.com 
    > Created Time: Áù  9/ 8 18:30:13 2018
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int a[1010] ;
int dp[1010] ;
int main()
{
	int n ;
	cin >> n ;
	for (int i = 1; i <= n; i ++)
		scanf("%d", &a[i]) ;
	for (int i = 1; i <= n; i ++) {
		dp[i] = 1 ;
		for (int j = 1; j < i; j ++)
			if (a[j] < a[i])
				dp[i] = max(dp[i], dp[j] + 1) ;
	}
	int ans = 0 ;
	for (int i = 1; i <= n; i ++)
		ans = max(ans, dp[i]) ;
	printf("%d\n", ans) ;
	return 0 ;
}