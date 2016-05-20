#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define MAX 1000000

using namespace std;

/*
  入力によって与えられる各範囲に関して開始時間と終了時間のペアを作る。
  このときリピートする範囲に関してはそれぞれペアを生成する。
  作られたペアの列を開始時間にて昇順にソートを行い、
  隣接する各範囲に関して、終了時間と開始時間が被らないかを検証する。
  被っていた場合はCONFLICTを出力し、それ以外はNO CONFLICTを出力する。
 */

int main()
{

	int n, m;
	int cnt = 1;
	while (cin >> n >> m, n || m) {
		cnt++;
		vector<pair<int, int> > t;

		int st, en, rep;
		for (int i=0; i<n; i++) {
			cin >> st >> en;
			t.push_back(make_pair(st, en));
		}

		for (int i=0; i<m; i++) {
			cin >> st >> en >> rep;

			int es = st + rep, ee = en + rep;
			while (es <= MAX){
				t.push_back(make_pair(es, ee));
				es+=rep; ee=min(ee + rep, MAX);
			}
			t.push_back(make_pair(st, en));
		}

		sort(t.begin(), t.end());

		bool is_ok = true;
		for (int i=0; i<t.size()-1; i++) {
			if(t[i].second > t[i+1].first) {
				is_ok = false;
				break;
			}
		}

		if (!is_ok) cout << "CONFLICT" << endl;
		else cout << "NO CONFLICT" << endl;
	}

	return 0;
}
