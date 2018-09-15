/*************************************************************************
 > File Name: D.cpp
 > Author: wennitao
 > Mail: wennitao@126.com
 > Created Time: Áù  9/ 8 18:33:39 2018
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int INF = 0x3f3f3f3f ;
char s[2010] ;
int val[26] ;
int dp[2010][2010] ;
int main()
{
    int n, m ;
    scanf("%d%d", &m, &n) ;
    scanf("%s", s + 1) ;
    for (int i = 1; i <= m; i ++) {
        char c[10] ;
        int a, b ;
        scanf("%s%d%d", c, &a, &b) ;
        val[c[0] - 'a'] = min(a, b) ;
    }
    for (int len = 2; len <= n; len ++)
        for (int l = 1; l <= n - len + 1; l ++) {
            int r = l + len - 1 ;
			dp[l][r] = INF ;
            if (s[l] == s[r]) dp[l][r] = min(dp[l][r], dp[l + 1][r - 1]) ;
            dp[l][r] = min(dp[l][r], min(dp[l + 1][r] + val[s[l] - 'a'], dp[l][r - 1] + val[s[r] - 'a'])) ;
        }
    printf("%d\n", dp[1][n]) ;
    return 0 ;
}