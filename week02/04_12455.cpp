/*
  方針:
  数列に対して、使用する・使用しないの状態をビットを用いて全て検証し、
  与えられたnを組み合わせが存在するか検証する。
  数列の長さmも最大20であり、
  2^m 程度の計算量で収まるため、TLEもおこならない。
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	cin >> t;

	while (t--) {
		int n, m, sum;
		cin >> n >> m;

		vector<int> p(m);
		for (int i=0; i<m; i++) cin >> p[i];

		bool f = false;
		for (int i=0; i<(1<<(m+1)); i++) {
			sum = 0;

			for (int j=0; j<m; j++) {
				if (i&(1<<j)) sum += p[j];
			}

			if (sum == n) {
				f = true;
				cout << "YES" << endl;
				break;
			}
		}

		if (!f) cout << "NO" << endl;
	}
	return 0;
}
