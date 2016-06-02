#include <iostream>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

int n;
int color[201];

bool bipartite(vector<int> *e, int cur, int col, int *cnt)
{
	color[cur] = col;
	cnt[col+1]++;

	for (int i=0; i<e[cur].size(); i++) {
		if (color[e[cur][i]] == col) return false;
		if (color[e[cur][i]] == 0 && !bipartite(e, e[cur][i], -col, cnt)) return false;
	}

	return true;
}

int main()
{
	int t;
	cin >> t;

	while (t--) {
		int m;
		cin >> n >> m;

		vector<int> edge[n];
		for (int i=0; i<m; i++) {
			int a, b;
			cin >> a >> b;
			edge[a].push_back(b);
			edge[b].push_back(a);
		}

		memset(color, 0, sizeof(color));

		int sum = 0;
		bool able = true;
		for (int i=0; i<n; i++) {
			if (!color[i]) {
				int cnt[3] = {0, 1, 0};
				if (!bipartite(edge, i, 1, cnt)) {
					able = false;
					break;
				}
				sum += max(cnt[1], min(cnt[0], cnt[2]));
			}
		}

		if (!able) {
			cout << -1 << endl;
		} else {
			cout << sum << endl;
		}
	}

	return 0;
}
