#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	double p;

	while (cin >> n >> p, n) {
		double pb[501], dp[501][501];

		pb[0] = 1.0;
		dp[0][0] = 1.0;
		for (int i=1; i<=n; i++) {
			dp[0][i] = 1.0;
			pb[i] = pb[i-1] * p;
		}

		for (int i=1; i<=n; i++) {
			for (int j=0; j<=n; j++) {
				if (j == i - 1) {
					dp[i][j] = dp[i-1][j] - pb[j+1];
				} else if (j < i-1) {
					dp[i][j] = dp[i-1][j] - dp[i-2-j][j] * (1-p) * pb[j+1];
				} else {
					dp[i][j] = dp[i-1][j];
				}
			}
		}

		double sum = 0.0;
		for (int i=1; i<=n; i++) {
			sum += (dp[n][i] - dp[n][i-1]) * i;
		}

		printf("%.6lf\n", sum);
	}

	return 0;
}
