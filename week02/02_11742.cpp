/*
  方針:
  全ての席順の組み合わせを列挙し、
  それぞれが条件を満たすか検証する。
  条件を満たすものの数を数え、出力する。

  nが高々8しかないため、8!=40320のループ、
  また、クエリの数 m=20 程度のため、時間内に収まる。
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	int n, m;
	while (cin >> n >> m, n || m) {
		vector<int> ta;
		vector<int> a(m), b(m), v(m);

		for (int i=0; i<n; i++) ta.push_back(i);
		for (int i=0; i<m; i++) cin >> a[i] >> b[i] >> v[i];

		int ans = 0;
		do {
			bool correct = true;
			for (int i=0; i<m; i++) {
				if (v[i] > 0) {
					if (abs(ta[a[i]] - ta[b[i]]) > v[i]) {
						correct = false;
					}
				} else {
					if (abs(ta[a[i]] - ta[b[i]]) < -v[i]) {
						correct = false;
					}
				}
			}

			if (correct) ans++;

		} while (next_permutation(ta.begin(), ta.end()));

		cout << ans << endl;
	}

	return 0;
}
