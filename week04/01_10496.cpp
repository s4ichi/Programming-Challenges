#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <cstdio>
#include <map>
#include <numeric>

using namespace std;

int main()
{
	int t;
	cin >> t;

	while (t--) {
		int h, w;
		int stx, sty;
		int n;

		cin >> h >> w;
		cin >> stx >> sty;
		cin >> n;
		n++;

		vector<pair<int, int> > p(n);
		for (int i=1; i<n; i++) {
			cin >> p[i].first >> p[i].second;
		}
		p[0].first = stx; p[0].second = sty;

		vector<vector<int> > dis(n, vector<int>(n, INT_MAX/2));
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				dis[i][j] = dis[j][i] =
					abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second);
			}
		}

		vector<vector<int> > dp(n, vector<int>(1<<n, INT_MAX/2));
		dp[0][(1<<n)-1] = 0;

		for (int k=(1<<n)-1; k>=0; k--) {
			for (int i=0; i<n; i++) {
				for (int j=0; j<n; j++) {
					if (!((k>>j)&1)) {
						dp[i][k] = min(dp[i][k], dp[j][k|1<<j] + dis[i][j]);
					}
				}
			}
		}

		cout << "The shortest path has length " << dp[0][0] << endl;
	}

	return 0;
}
