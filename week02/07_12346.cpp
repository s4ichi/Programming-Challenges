/*
  方針:
  全ての water gate に関する順列を列挙し、一時間あたりの放水量とコストを求める。
  求まったものをコストで昇順にソートする。

  各クエリの入力に対して、最も低コストで時間 * 放水量がクエリの要求を満たすもの
  を先頭から探索することで答えが求まる。

  また、クエリに対する探索は二分探索などを用いたほうが高速だが、
  今回の問題では全探索を用いても十分に間に合う。
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define mp make_pair

using namespace std;

typedef pair<int, int> pii;

int main()
{
	int n, m;
	cin >> n;

	vector<pii> v(n);
	for (int i=0; i<n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	vector<pii> combi;
	for (int i=0; i<(1<<n); i++) {
		int cost = 0, water = 0;

		for (int j=0; j<n; j++) {
			if ((i & (1<<j)) == 0) continue;

			water += v[j].first;
			cost += v[j].second;
		}

		combi.push_back(mp(cost, water));
	}

	sort(combi.begin(), combi.end());

	cin >> m;

	for (int i=0; i<m; i++) {
		int water, time;
		bool possible = false;

		cin >> water >> time;

		for (int j=0; j<(1<<n); j++) {
			if (combi[j].second * time < water) continue;

			cout << "Case " << i+1 << ": " << combi[j].first << endl;
			possible = true;
			break;
		}

		if (!possible) cout << "Case " << i+1 << ": IMPOSSIBLE" << endl;
	}

	return 0;
}
