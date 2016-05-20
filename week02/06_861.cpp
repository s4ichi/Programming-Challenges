/*
  方針:
  盤面を白黒で塗り、斜めにみることで、ビジョップの配置によって
  影響される範囲が同色かつ同じラインであることがわかる。

  その性質より、以下の漸化式を立てる。

  f[a][b][c] : 斜めから見たライン上の橋からa番目にビジョップを置く時、
               b個のビジョップを既に配置していてc個のビジョップをまだ置いていない場合の組み合わせの総数

  この式を元に、斜めに見た盤面の左右から同時に配置を始めると考え、
  置く場合、片方置く場合、両方置く場合の3通りの総数を数え上げる。

  また、盤面が偶数・奇数の場合で初期の配置も違うため、考慮する。

  この処理を行う際はメモ化をすることで再帰における処理数を削減し、問題の制限時間を守ることができる。
 */

#include <iostream>

typedef long long ll;

using namespace std;

int n, k;
ll memo[65][65][65];

ll calc(int line,int cnt,int rest)
{
	if (rest <= 0) return 1;
	if (line > n || rest > n) return 0;
	if (memo[line][cnt][rest] >= 0) return memo[line][cnt][rest];

	ll ret = 0;

	ret += calc(line+2, cnt+2, rest);

	if (line == n){
		ret += cnt * calc(line+2, cnt+1, rest-1);
	} else {
		ret += 2 * cnt * calc(line+2, cnt+1, rest-1);
	}

	if (cnt >= 2 && rest >= 2 && line != n) {
		ret += cnt * (cnt - 1) * calc(line+2, cnt, rest-2);
	}

	memo[line][cnt][rest] = ret;
	return ret;
}

int main()
{
	while(cin >> n >> k, n || k){
		for (int i=0; i<65; i++) {
			for (int j=0; j<65; j++) {
				for (int l=0; l<65; l++) {
					memo[i][j][l] = -1;
				}
			}
		}

		ll ans = 0;
		if (n % 2 == 0) {
			for (int i=0; i<=k; i++) {
				ans += calc(1, 1, i) * calc(1, 1, k-i);
			}
		} else {
			for (int i=0; i<=k; i++) {
				ans += calc(1, 1, i) * calc(2, 2, k-i);
			}
		}

		cout << ans << endl;
	}
	return 0;
}
