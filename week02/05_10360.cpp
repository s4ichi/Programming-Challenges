/*
  方針:
  問題に与えられている最大サイズのマップを用意し、
  マウスの存在情報を示す入力に対してマップへ以下の操作を加える。

  ・dを爆弾の半径とする。
  ・マウスの存在点を中心とし、半径dの範囲内の各点へマウスの匹数を加える。

  この操作を全ての入力に対して行うと、
  マップの各点には、爆弾を設置した際に影響を及ぼすマウスの匹数の総数が
  表されることになる。

  よって入力に対し操作を行った後、マップ上の点より最大の匹数となる点を
  見つけ、その点の場所と匹数を出力する。
   */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
	int t;
	cin >> t;

	while (t--) {
		int m[1030][1030];
		for (int i=0; i<1030; i++) {
			for (int j=0; j<1030; j++) {
				m[i][j] = 0;
			}
		}

		int n, d;
		cin >> d >> n;

		for (int i=0; i<n; i++) {
			int a, b, v;
			cin >> a >> b >> v;

			for (int p=max(0, a-d); p<=min(1025, a+d); p++) {
				for (int q=max(0, b-d); q<=min(1025, b+d); q++) {
					m[p][q] += v;
				}
			}
		}

		int ma = -1, x, y;
		for (int i=0; i<=1025; i++) {
			for (int j=0; j<=1025; j++) {
				if(ma < m[i][j]) {
					ma = m[i][j];
					x = i;
					y = j;
				}
			}
		}

		cout << x << " " << y << " " << ma << endl;
	}
	return 0;
}
