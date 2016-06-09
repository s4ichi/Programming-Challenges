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

typedef pair<double, double> Point;

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

double dist(Point a, Point b)
{
	return sqrt((a.first - b.first) * (a.first - b.first) +
				(a.second - b.second) * (a.second - b.second));
}

int main()
{
	int n, m, s, v;

	while (scanf("%d%d%d%d",&n, &m, &s, &v) != EOF) {
		vector<Point> gophers(n);
		vector<Point> holes(m);

		for (int i=0; i<n; i++) {
			cin >> gophers[i].first >> gophers[i].second;
		}

		for (int i=0; i<m; i++) {
			cin >> holes[i].first >> holes[i].second;
		}

		Dinic<int, 20000> dinic;

		for (int i=0; i<n; i++) {
			dinic.add(0, i+1, 1);
		}

		for (int i=0; i<m; i++) {
			dinic.add(n+i+1, n+m+1, 1);
		}

		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				if (dist(gophers[i], holes[j]) <= (double)(s * v)) {
					dinic.add(i+1, n+j+1, 1);
				}
			}
		}

		cout << n - dinic.exec(0, n+m+1) << endl;
	}

	return 0;
}
