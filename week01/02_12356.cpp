#include <iostream>
#include <algorithm>

#define S 100002

using namespace std;

/*
  方針:
  各兵士の左右の番号を記憶した配列を左・右でそれぞれl, rで宣言をする。
  爆破の範囲(st, en)が与えられたとき、
  stの左を指す番号が指す右の番号をenの右の番号に置き換え、
  enの右を指す番号が指す左の番号をstの左の番号に置き換える。
  各クエリについて上記の操作を行い、出力をする。
 */

int main()
{
	int l[S] = {0}, r[S] = {0};
	int s, b;

	while (cin >> s >> b, s && b) {
		for (int i=1; i<=s; i++) {
			l[i] = i - 1;
			r[i] = i + 1;
		}
		r[s] = 0;

		int st, en;
		for (int i=0; i<b; i++) {
			cin >> st >> en;

			if (l[st] == 0) cout << "* ";
			else cout << l[st] << ' ';

			if (r[en] == 0) cout << '*' << endl;
			else cout << r[en] << endl;

			r[l[st]] = r[en];
			l[r[en]] = l[st];
		}
		cout << '-' << endl;
	}

	return 0;
}
