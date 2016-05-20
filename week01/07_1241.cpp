#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <cmath>

#define DUMP(x)  cerr << #x << " = " << (x) << endl;

using namespace std;

/*
  問題より、選手数が2^nのため、トーナメント表は完全二分木であることがわかる。
  よって、辞退をした選手の葉のノードを-1,
  それ以外を0とした二分木を初期状態として生成する。

  各トーナメントの回戦(2^nの選手のためn回戦が存在する)において、
  それぞれの節点(試合)におけるleft, rightのノードが持つ数字が両方-1の場合、-1をを引き継ぎ、
  片方だけ-1の場合、不戦勝が起こるため答えをカウントすつ。

  上記の方法を1回戦、2回戦...と走査し、
  決勝まで走査が終えたときのカウントした値が不戦勝があった試合の総数となる。
 */

int main()
{
	int cases;
	cin >> cases;

	for (int c=0; c<cases; c++) {
		int n, m;
		cin >> n >> m;

		int tree[2014*2+1] = {0};

		int wo;
		for (int i=0; i<m; i++) {
			cin >> wo;
			tree[(1<<n) + wo - 1] = -1;
		}

		int cnt = 0;
		for (int i=1<<(n-1); i>0; i>>=1) {
			for(int j=i; j<(i<<1); j++) {
				if (tree[j*2] == -1 && tree[j*2+1] == -1) {
					tree[j] = -1;
				} else if (tree[j*2] == -1 || tree[j*2+1] == -1) {
					cnt++;
				}
			}
		}

		cout << cnt << endl;
	}
	return 0;
}
