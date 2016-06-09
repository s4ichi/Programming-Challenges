#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

#define INF 1 << 27

using namespace std;

int main()
{
	int t = 1;
	int p, r;
	while (cin >> p >> r, p && r) {
		int d[51][51];
		for (int i=0; i<=p; i++) {
			for (int j=0; j<=p; j++) {
				d[i][j] = INF;
			}
			d[i][i] = 0;
		}

		map<string, int> to_i;
		int ind = 1;

		for (int i=0; i<r; i++) {
			string a, b;
			cin >> a >> b;

			if (!to_i[a]) to_i[a] = ind++;
			if (!to_i[b]) to_i[b] = ind++;

			d[to_i[a]][to_i[b]] = d[to_i[b]][to_i[a]] = 1;
		}

		for (int k=1; k<=p; k++) {
			for (int i=1; i<=p; i++) {
				for (int j=1; j<=p; j++) {
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}

		int ans = 0;
		for (int i=1; i<=p; i++) {
			for (int j=1; j<=p; j++) {
				ans = max(ans, d[i][j]);
			}
		}

		cout << "Network " << t++ << ": ";

		if (ans >= INF) {
			cout << "DISCONNECTED" << endl;
		} else {
			cout << ans << endl;
		}
		cout << endl;
	}

	return 0;
}
