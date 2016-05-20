/*
  方針:
  greedy を用いて計算を行う。
  竜の頭の高さとナイトの高さ(チップ数)をそれぞれ昇順にソートし、
  竜の高さを超える最も低いナイトを貪欲に選ぶ。

  また、ナイトの数が竜の頭の数より少ない場合や、
  竜の頭の高さを超えるナイトがいない場合は Loowater is doomed! を出力する。

  もし全ての竜の頭に対応するナイトが存在した場合はそのチップの合計を出力する。
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, m;
	while (cin >> n >> m, n || m) {
		vector<int> heads(n);
		vector<int> knights(m);

		for (int i=0; i<n; i++) cin >> heads[i];
		for (int i=0; i<m; i++) cin >> knights[i];

		sort(heads.begin(), heads.end());
		sort(knights.begin(), knights.end());

		int charge = 0;
		bool f = true;
		vector<int>::iterator h = heads.begin();
		vector<int>::iterator k = knights.begin();
		while (h != heads.end()) {
			if (k == knights.end()) {
				cout << "Loowater is doomed!" << endl;
				f = false;
				break;
			}

			if (*h <= *k) {
				charge += *k;
				h++;
			}

			k++;
		}

		if (f) cout << charge << endl;
	}

	return 0;
}
