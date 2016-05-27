#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
	int len, n;
	while (cin >> len, len) {
		cin >> n;

		vector<int> cut(n+2);
		cut[0] = 0;
		cut[n+1] = len;
		for (int i=1; i<=n; i++) {
			cin >> cut[i];
		}
		n++;

		int dp[52][52];
		fill(dp[0], dp[52], INT_MAX/3);

		for (int i=0; i<n; i++) {
			dp[i][i+1] = 0;
		}

		for (int width=2; width<=n; width++) {
			for (int i=0; i<=(n - width); i++) {
				int l = i + width;
				for (int j=i+1; j<l; j++) {
					dp[i][l] = min(dp[i][l], dp[i][j] + dp[j][l] + (cut[l] - cut[i]));
				}
			}
		}

		cout << "The minimum cutting is " <<  dp[0][n] << "." <<endl;
	}

	return 0;
}
