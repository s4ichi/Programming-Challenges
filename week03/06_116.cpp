#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace std;

int main()
{
	int n, m;
	while(scanf("%d %d", &n, &m) != EOF) {
		vector<vector<int> >
			t(n, vector<int>(m)),
			dp(n, vector<int>(m)),
			prev(n, vector<int>(m));


		for (int i=0; i<n; i++) {
			for ( int j=0; j<m; j++) {
				cin >> t[i][j];
				if (j == m-1) dp[i][j] = t[i][j];
			}
		}

		for (int j=m-1; j>0; j--) {
			for (int i=0; i<n; i++) {
				int ma = INT_MAX;

				for (int k=-1; k<=1; k++) {
					int idx = (i + k + n) % n;

					if (dp[idx][j] < ma || dp[idx][j] == ma && idx < prev[i][j-1]) {
						ma = dp[idx][j];
						prev[i][j-1] = idx;
					}
				}
				dp[i][j-1] = ma + t[i][j-1];
			}
		}

		int top = INT_MAX, idx;
		for (int i=0; i<n; i++) {
			if (top > dp[i][0]) {
				top = dp[i][0];
				idx = i;
			}
		}

		for (int i=0; i<m; i++) {
			cout << idx + 1;
			idx = prev[idx][i];
			if (i < m-1) cout << " ";
	 	}

		cout << endl << top << endl;
	}

	return 0;
}
