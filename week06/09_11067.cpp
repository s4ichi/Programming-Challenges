#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
	int w, h;

	while (cin >> w >> h, w && h) {
		int n;
		cin >> n;

		bool m[101][101];
		memset(m, false, sizeof(m));

		for (int i=0; i<n; i++) {
			int x, y;
			cin >> x >> y;
			m[y][x] = true;
		}

		int dp[101][101];
		memset(dp, 0, sizeof(dp));

		dp[0][0] = 1;

		for (int i=0; i<=h; i++) {
			for (int j=0; j<=w; j++) {
				if (m[i][j]) continue;
				if (i-1 >= 0) if (!m[i-1][j]) dp[i][j] += dp[i-1][j];
				if (j-1 >= 0) if (!m[i][j-1]) dp[i][j] += dp[i][j-1];
			}
		}

		if (!dp[h][w]) {
			cout << "There is no path." << endl;
		} else if (dp[h][w] == 1) {
			cout << "There is one path from Little Red Riding Hood's house to her grandmother's house." << endl;
		} else {
			cout << "There are " << dp[h][w] <<" paths from Little Red Riding Hood's house to her grandmother's house." << endl;
		}
	}

	return 0;
}
