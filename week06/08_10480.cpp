#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <cstring>
#include <algorithm>

#define INF 1<<28

using namespace std;

template<typename T, int V>
struct Dinic {
	struct Edge {
		int to, rev;
		T cap;
	};

	vector<Edge> g[V];
	int level[V];
	int iter[V];

	Dinic() {
		for (int i = 0; i < V; i++) {
			g[i].clear();
		}
	}

	void add_multi(int from, int to, T cap) {
		g[from].push_back(Edge{to, (int)g[to].size(), cap});
		g[to].push_back(Edge{from, (int)g[from].size()-1, cap});
	}

	void add(int from, int to, T cap) {
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

	T dfs(int v, int t, T f) {
		if (v == t) return f;
		for (int &i = iter[v]; i < (int)g[v].size(); i++) {
			Edge &e = g[v][i];
			if (e.cap <= 0) continue;
			if (level[v] < level[e.to]) {
				T d = dfs(e.to, t, min(f, e.cap));
				if (d <= 0) continue;
				e.cap -= d;
				g[e.to][e.rev].cap += d;
				return d;
			}
		}
		return 0;
	}

	T exec(int s, int t) {
		T flow = 0;
		while (true) {
			bfs(s);
			if (level[t] < 0) return flow;
			fill_n(iter, V, 0);
			T f;
			while ((f = dfs(s, t, INF)) > 0) {
				flow += f;
			}
		}
	}
};


int main()
{
	int n, m;

	while (cin >> n >> m, n && m) {
		Dinic<int, 501> dinic;

		vector<pair<int, int> > e;
		for (int i=0; i<m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			e.push_back(make_pair(a, b));
			dinic.add_multi(a, b, c);
		}

		dinic.exec(1, 2);

		for (int i=0; i<m; i++) {
			if ((dinic.level[e[i].first] != -1 && dinic.level[e[i].second] == -1) ||
				(dinic.level[e[i].first] == -1 && dinic.level[e[i].second] != -1)) {
				cout << e[i].first << " " << e[i].second << endl;
			}
		}
		cout << endl;
	}

	return 0;
}
