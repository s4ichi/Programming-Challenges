#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>

#define INF 1<<28
#define V 40

using namespace std;

struct Edge {
	int to, rev;
	int cap;
};

struct Dinic {
	vector<Edge> g[V];
	int level[V];
	int iter[V];

	Dinic() {
		for (int i = 0; i < V; i++) {
			g[i].clear();
		}
	}

	void add(int from, int to, int cap) {
		g[from].push_back(Edge{to, (int)g[to].size(), cap});
		g[to].push_back(Edge{from, (int)g[from].size()-1, 0});
	}

	void bfs(int s) {
		fill_n(level, V, -1);
		queue<int> que;
		level[s] = 0;
		que.push(s);
		while (!que.empty()) {
			int v = que.front(); que.pop();
			for (Edge e: g[v]) {
				if (e.cap <= 0) continue;
				if (level[e.to] < 0) {
					level[e.to] = level[v] + 1;
					que.push(e.to);
				}
			}
		}
	}

	int dfs(int v, int t, int f) {
		if (v == t) return f;
		for (int &i = iter[v]; i < (int)g[v].size(); i++) {
			Edge &e = g[v][i];
			if (e.cap <= 0) continue;
			if (level[v] < level[e.to]) {
				int d = dfs(e.to, t, min(f, e.cap));
				if (d <= 0) continue;
				e.cap -= d;
				g[e.to][e.rev].cap += d;
				return d;
			}
		}
		return 0;
	}

	int exec(int s, int t) {
		int flow = 0;
		while (true) {
			bfs(s);
			if (level[t] < 0) return flow;
			fill_n(iter, V, 0);
			int f;
			while ((f = dfs(s, t, INF)) > 0) {
				flow += f;
			}
		}
	}
};

int main()
{
	string buf;

	while (1) {
		getline(cin, buf);
		if (cin.eof()) break;

		vector<string> inputs;
		inputs.push_back(buf);

		while (1) {
			getline(cin, buf);
			if (buf == "\0") break;
			inputs.push_back(buf);
		}

		Dinic dinic;

		int set_cnt = 0;
		for (int i=0; i<inputs.size(); i++) {
			string s = inputs[i];

			int a = s[0] - 'A' + 1,
				b = s[1] - '0';

			dinic.add(0, a, b);

			int idx = 3;
			while (s[idx] != ';') {
				int c = s[idx++] - '0';
				dinic.add(a, c + 27, INF);
			}

			set_cnt += b;
		}

		for (int i=27; i<37; i++) {
			dinic.add(i, 37, 1);
		}

		if (dinic.exec(0, 37) != set_cnt) {
			cout << "!" << endl;
		} else {
			for (int i=27; i<37; i++) {
				bool ok = false;
				for (int j=0; j<dinic.g[i].size(); j++) {
					int to = dinic.g[i][j].to,
						cap = dinic.g[i][j].cap;
					if (cap == 1 && to >= 1 && to <= 26) {
						cout << (char)('A' + dinic.g[i][j].to - 1);
						ok = true;
						break;
					}
				}

				if (!ok) cout << "_";
			}
			cout << endl;
		}
	}

	return 0;
}
