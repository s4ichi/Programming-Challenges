#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
	int t;
	cin >> t;

	while (t--) {
		int m, s;
		cin >> m >> s;

		int dp[301][301];
		vector<pair<int, int> > v(m);

		for (int i=0; i<m; i++) {
			cin >> v[i].first >> v[i].second;
		}

		for (int i=0; i<=s; i++) {
			for (int j=0; j<=s; j++) {
				dp[i][j] = 1 << 20;
			}
		}

		dp[0][0] = 0;

		for (int i=0; i<m; i++) {
			for (int j=v[i].first; j<=s; j++) {
				for (int k=v[i].second; k<=s; k++) {
					dp[j][k] = min(dp[j][k], dp[j - v[i].first][k - v[i].second] + 1);
				}
			}
		}

		int ans = 1 << 20;
		for (int j=0; j<=s; j++) {
			for (int k=0; k<=s; k++) {
				if (j * j + k * k == s * s) {
					ans = min(ans, dp[j][k]);
				}
			}
		}

		if (ans == 1 << 20) cout << "not possible" << endl;
		else cout << ans << endl;

	}
	return 0;
}
