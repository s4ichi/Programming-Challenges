#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/*
  入力のベースとなる正方文字形をbase, 回転を用いる正方文字形をroteとする。
  roteにおいて事前に回転された形を計算する。
  baseの左上より、各点において4つroteがマッチするかを判別し、それぞれカウントする。
 */

int main()
{
	int n, m;
	while (cin >> n >> m, n && m) {
		vector<string> base(n);
		vector< vector<string> > rote(4, vector<string>(m));
		int ans[4] = {0};

		for (int i=0; i<n; i++) cin >> base[i];

		for (int i=0; i<m; i++) {
			cin >> rote[0][i];
			for(int j=1; j<4; j++)rote[j][i] = rote[0][i];
		}

		for (int i=0; i<m; i++) {
			for (int j=0; j<m; j++) {
				rote[1][i][j] = rote[0][m - 1 - j][i];
				rote[2][i][j] = rote[0][m - 1 - i][m - 1 - j];
				rote[3][i][j] = rote[0][j][m - 1 - i];
			}
		}


		for (int i=0; i<n-m+1; i++) {
			for (int j=0; j<n-m+1; j++) {
				for (int k=0; k<4; k++) {
					bool exist = true;
					for (int p=0; p<m; p++) {
						for (int q=0; q<m; q++) {
							if (base[i + p][j + q] != rote[k][p][q]) {
								exist = false;
							}
							if (!exist) break;
						}
						if (!exist) break;
					}
					if (exist) ans[k]++;
				}
			}
		}

		for (int i=0; i<4; i++) {
			cout << ans[i];
			if (i < 3) cout << " ";
		}
		cout << endl;
	}
	return 0;
}
