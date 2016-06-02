#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <map>
#include <numeric>
#include <set>

using namespace std;

typedef pair<int, int> pii;

int main()
{
	int cs; cin >> cs;

	for (int t=1; t<=cs; t++) {
		int r, c, m, n, w;
		cin >> r >> c >> m >> n >> w;

		set<pii> s;
		set<pii>::iterator it;

		for (int i=-1; i<=1; i+=2) {
			for (int j=-1; j<=1; j+=2) {
				s.insert(make_pair(i*n, j*m));
				s.insert(make_pair(i*m, j*n));
			}
		}

		bool water[101][101], f[101][101];;
		fill(water[0], water[101], false);
		fill(f[0], f[101], false);
		f[0][0] = true;

		for (int i=0; i<w; i++) {
			int y, x;
			cin >> y >> x;
			water[y][x] = true;
		}

		int rc[101][101];
		fill(rc[0], rc[101], 0);

		queue<pii> q;
		q.push(make_pair(0, 0));

		while (!q.empty()) {
			pii cur = q.front(); q.pop();

			for(it=s.begin(); it!=s.end(); it++) {
				int y = cur.first + (*it).first;
				int x = cur.second + (*it).second;

				if (y >= r || y < 0 || x >= c || x < 0) continue;

				rc[y][x]++;

				if (!f[y][x] && !water[y][x]) {
					f[y][x] = true;
					q.push(make_pair(y, x));
				}
			}
		}

		int white = 0, black = 0;
		for (int i=0; i<r; i++) {
			for (int j=0; j<c; j++) {
				if (!f[i][j] || water[i][j]) continue;
				if (rc[i][j]%2 == 0) white++;
				else black++;
			}
		}

		cout << "Case " << t << ": " << white << " " << black << endl;
	}

	return 0;
}
