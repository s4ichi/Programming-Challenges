#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

int cnt;
bool del[1001][1001];
int low[1001], pre[1001];

int walk(int cur, int from, vector<int> *e) {
	low[cur] = pre[cur] = ++cnt;

	for (int i=0; i< e[cur].size(); i++) {
		int to = e[cur][i];
		if (del[cur][to]) continue;

		if (!pre[to]) {
			low[cur] = min(low[cur], walk(to, cur, e));

			if (pre[to] != low[to]) {
				del[to][cur] = true;
			}
		} else if (from != to) {
			low[cur] = min(low[cur], low[to]);
			del[to][cur] = true;
		}
	}

	return low[cur];
}

int main() {
	int n, m, t = 1;

	while (cin >> n >> m, n && m) {
		vector<int> edge[n+1];
		for (int i=0; i<m; i++) {
			int a, b;
			cin >> a >> b;
			edge[a].push_back(b);
			edge[b].push_back(a);
		}

		cnt = 0;
		memset(low, false, sizeof(pre));
		memset(pre, false, sizeof(low));
		memset(del, false, sizeof(del));

		cout << t++ << endl << endl;

		for (int i=1; i<=n; i++) {
			if (!pre[i]) walk(i, i, edge);
		}

		for (int i=1; i<=n; i++) {
			for (int j=0; j<edge[i].size(); j++) {
				int to = edge[i][j];
				if (!del[i][to]) {
					cout << i << " " << to << endl;
				}
			}
		}
		cout << "#" << endl;
	}

	return 0;
}
