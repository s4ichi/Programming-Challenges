#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define INF 1 << 27

using namespace std;

int main()
{
	int p, r, bh, of, yh, m;

	while (scanf("%d%d%d%d%d%d", &p, &r, &bh, &of, &yh, &m) != EOF) {

		bool f[101];
		int d[101][101], d2[101][101];

		for (int i=1; i<=p; i++) {
			for (int j=1; j<=p; j++) {
				d[i][j] = d2[i][j] = INF;
			}
			d[i][i] = d2[i][i] = 0;
			f[i] = true;
		}

		for (int i=0; i<r; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			d[a][b] = d[b][a] = d2[a][b] = d2[b][a] = c;
		}

		for (int k=1; k<=p; k++) {
			for (int i=1; i<=p; i++) {
				for (int j=1; j<=p; j++) {
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}

		for (int i=1; i<=p; i++) {
			if (d[bh][i] + d[i][of] == d[bh][of]) f[i] = false;
		}

		if (!f[yh] || !f[m]) {
			cout << "MISSION IMPOSSIBLE." << endl;
			continue;
		}

		for (int k=1; k<=p; k++) {
			if (!f[k]) continue;
			for (int i=1; i<=p; i++) {
				if (!f[i]) continue;
				for (int j=1; j<=p; j++) {
					if (!f[j]) continue;
					d2[i][j] = min(d2[i][j], d2[i][k] + d2[k][j]);
				}
			}
		}

		if (d2[yh][m] == INF) {
			cout << "MISSION IMPOSSIBLE." << endl;
		} else {
			cout << d2[yh][m] << endl;
		}
	}

	return 0;
}
