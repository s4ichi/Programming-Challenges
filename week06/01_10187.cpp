#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <string>

using namespace std;

typedef pair<int, pair<int, int> > pipii;

map<string, int> f;
int idx;

int index(string name)
{
	if (!f[name]) return f[name] = idx++;
	return f[name];
}

int main()
{
	int cs;
	cin >> cs;

	for (int t=1; t<=cs; t++) {
		int n;
		cin >> n;

		idx = 1;
		f.clear();

		vector<pipii> g[101];
		for (int i=0; i<n; i++) {
			string from, to;
			int b, e;
			cin >> from >> to >> b >> e;

			if ((b > 6 && b < 18) || ((b+e)%24 > 6 && (b+e)%24 < 18) || e > 12) continue;

			if (b >= 18) b -= 18;
			else b += 6;

			g[index(from)].push_back(make_pair(index(to), make_pair(b, b+e)));
		}

		int ans = -1;

		string begin, end;
		cin >> begin >> end;

		bool flg[101];
		memset(flg, false, sizeof(flg));

		priority_queue<pipii, vector<pipii>, greater<pipii> > q;
		q.push(make_pair(0, make_pair(index(begin), 0)));
		flg[index(begin)] = true;

		while (!q.empty()) {
			pipii p = q.top(); q.pop();
			int cur = p.second.first,
				time = p.second.second,
				day = p.first;

			flg[cur] = true;

			if (cur == index(end)) {
				ans = day;
				break;
			}

			for (int i=0; i<g[cur].size(); i++) {
				int to = g[cur][i].first,
					st = g[cur][i].second.first,
					en = g[cur][i].second.second;

				if (!flg[to]) {
					if (time <= st) {
						q.push(make_pair(day, make_pair(to, en)));
					} else {
						q.push(make_pair(day+1, make_pair(to, en)));
					}
				}
			}
		}

		cout << "Test Case " << t << "." << endl;

		if (ans < 0) {
			cout << "There is no route Vladimir can take." << endl;
		} else {
			cout << "Vladimir needs " << ans << " litre(s) of blood." << endl;
		}

	}
	return 0;
}
