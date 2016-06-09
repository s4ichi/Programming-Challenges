#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int p;
	cin >> p;

	while (p--) {
		int n, e, t, m;
		cin >> n >> e >> t >> m;

		int d[101][101];
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				d[i][j] = 1 << 27;
			}
			d[i][i] = 0;
		}

		for (int i=0; i<m; i++) {
			int a, b, v;
			cin >> a >> b >> v;
			d[a-1][b-1] = v;
		}

		for (int k=0; k<n; k++) {
			for (int i=0; i<n; i++) {
				for (int j=0; j<n; j++) {
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}

		int cnt = 0;
		for (int i=0; i<n; i++) {
			if (d[i][e-1] <= t) cnt++;
		}

		cout << cnt << endl;
		if (p > 0) cout << endl;
	}

	return 0;
}
