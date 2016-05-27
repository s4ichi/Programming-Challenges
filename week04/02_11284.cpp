#include <cstdio>
#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
#include <numeric>

using namespace std;

int main(void) {
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;
		n++;

		vector<vector<double> > m1(n, vector<double>(n));

		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if (i == j) m1[i][j] = 0;
				else m1[i][j] = (double)INT_MAX;
			}
		}

		for (int i=0; i<m; i++) {
			int a, b;
			double c;
			cin >> a >> b >> c;
			m1[a][b] = m1[b][a] = min(m1[a][b], min(m1[b][a], c));
		}

		int p;
		cin >> p;

		vector<int> dvd(p);
		vector<double> score(p);

		vector<vector<double> > m2(p+1, vector<double>(p+1));
		vector<vector<double> > dp(p+1, vector<double>(1<<(p+1), (double)INT_MIN));

		for (int i=0; i<p; i++) cin >> dvd[i] >> score[i];

		for (int k=0; k<n; k++) {
			for (int i=0; i<n; i++) {
				for (int j=0; j<n; j++) {
					m1[i][j] = min(m1[i][j], m1[i][k] + m1[k][j]);
				}
			}
		}

		for (int i=0; i<p; i++) {
			m2[0][i+1] = m2[i+1][0] = m1[0][dvd[i]];
		}

		for (int i=1; i<=p; i++) {
			for (int j=1; j<=p; j++) {
				m2[i][j] = m1[dvd[i-1]][dvd[j-1]];
			}
		}

		for (int i=0; i<p+1; i++) {
			dp[i][(1<<(p+1))-1] = -m2[i][0];
		}

		for (int k=(1<<(p+1))-1; k>=0; k--) {
			for (int i=0; i<p+1; i++) {
				if (k&(1<<i)) {
					for (int j=0; j<p+1; j++) {
						if (!(k&(1<<j))) {
							dp[i][k] = max(dp[i][k], max(dp[i][k|(1<<j)], dp[j][k|(1<<j)] - m2[i][j] + score[j-1]));
						}
					}
				}
			}
		}

		if (dp[0][1] > 0 && dp[0][1] > 1e-9) {
			printf("Daniel can save $%.2lf\n", dp[0][1]);
		} else {
			printf("Don't leave the house\n");
		}
	}
}
