/*
  方針:
  greedy を用いて解を求める。
  弁償すべき値の適値は time と fine を用いて fine/time で求まることがわかる。
  よってその値を元に降順にソートを行い、先頭から番号を出力する。

 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
typedef pair<double, int> di;

bool comp(const di &l, const di &r)
{
	return l.first > r.first;
}

int main()
{
	int t;
	scanf("%d\n", &t);

	while (t--) {
		vector<di> v;
		int n, time, fine;
		cin >> n;

		for (int i=0; i<n; i++) {
			cin >> time >> fine;
			v.push_back(make_pair((double)fine/(double)time, i+1));
		}

		sort(v.begin(), v.end(), comp);

		for (int i=0; i<v.size(); i++) {
			if (i > 0) cout << ' ';
			cout << v[i].second;
		}
		cout << endl;

		if (t) cout << endl;
	}
	return 0;
}
