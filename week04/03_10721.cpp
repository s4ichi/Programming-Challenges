#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

int main()
{
	int n, m, k;
	while (scanf("%d %d %d", &n, &k, &m) != EOF) {
		ll dp[51][51];
		memset(dp, 0, sizeof(dp));

		for (int i=1; i<=n && i<=m ;i++) {
			dp[i][1] = 1;
		}

		for (int i=2; i<=k; i++) {
			for (int j=i; j<=n; j++) {
				for (int l=1; l<=m && l<=j; l++) {
					dp[j][i] += dp[j-l][i-1];
				}
			}
		}

		cout << dp[n][k] << endl;
	}

	return 0;
}
