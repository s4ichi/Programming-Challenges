#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

int node[1000001];
vector<int> topological_seq;

bool visit(vector<int> *e, int cur)
{
	node[cur] = 1;

	for (int i=0; i<e[cur].size(); i++) {
		if (node[e[cur][i]] == 2) continue;
		if (node[e[cur][i]] == 1) return false;
		if (!visit(e, e[cur][i])) return false;
	}

	topological_seq.push_back(cur);
	node[cur] = 2;

	return true;
}

int main()
{
	int m, n;
	while (cin >> m >> n, m || n) {
		topological_seq.clear();
		memset(node, 0, sizeof(node));

		vector<int> edge[m+1];
		for (int i=0; i<n; i++) {
			int a, b;
			cin >> a >> b;
			edge[a].push_back(b);
		}

		bool able = true;
		for (int i=1; i<=m; i++) {
			if (!node[i] && !visit(edge, i)) {
				able = false;
				break;
			}
		}

		if (!able) {
			cout << "IMPOSSIBLE" << endl;
		} else {
			reverse(topological_seq.begin(), topological_seq.end());
			for (int i=0; i<topological_seq.size(); i++) {
				cout << topological_seq[i] << endl;
			}
		}
	}

	return 0;
}
