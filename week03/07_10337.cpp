#include <iostream>
#include <vector>

using namespace std;

int main()
{
	const int h = 10;

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		n /= 100;

		int dp[11][1001], wind[11][1001];

		for (int i=h; i>0; i--) {
			for (int j=0; j<n; j++) {
				cin >> wind[i][j];
				dp[i][j] = 100000;
			}
		}

		dp[1][0] = 0;

		for (int j=0; j<=n; j++) {
			for (int i=1; i<=h; i++) {
				dp[i][j+1] = dp[i][j] + 30 - wind[i][j];

				if (i < h) {
					dp[i][j+1] = min(dp[i][j+1], dp[i+1][j] + 20 - wind[i+1][j]);
				}
				if (i > 1) {
					dp[i][j+1] = min(dp[i][j+1], dp[i-1][j] + 60 - wind[i-1][j]);
				}
			}
		}

		cout << dp[1][n] << endl << endl;
	}

	return 0;
}
