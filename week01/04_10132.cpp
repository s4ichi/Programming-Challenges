#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/*
  この問題における答えとなる文字列の長さは、
  入力にある最短と最長の文字列の長さの和であることがわかる。
  全ての互いに異なる文字列ペアに関して、
  長さが答えとマッチするようなものの総数をカウントする。
  問題の性質より、答えとなる文字列は存在することが決まっているため、
  カウントされた文字列の総数が最も多いものを解答とすることができる。
 */

bool comp( const string &left, const string &right ) {
	return left.size() > right.size();
}

int main()
{
	int n;
	string s;

	cin >> n;
	cin.ignore();
	getline(cin, s);

	for (int t=0; t<n; t++) {
		if (t > 0) cout << endl;

		vector<string> fl;

		while (getline(cin, s)) {
			if (s[0] == '\0' || s[0] == '\n') break;
			fl.push_back(s);
		}

		sort(fl.begin(), fl.end(), comp);

		map<string, int> m;
		int N = fl.size();
		int len = fl[0].size() + fl[N - 1].size();

		for (int i=0; i<N; i++) {
			for (int j=0; j<N; j++) {
				if (i == j) continue;
				if (fl[i].size() + fl[j].size() == len) {
					m[fl[i] + fl[j]]++;
				}
			}
		}

		int ma = 0;
		string ans;
		map<string, int>::iterator it = m.begin();
		while (it != m.end()) {
			if((*it).second > ma) {
				ma = (*it).second;
				ans = (*it).first;
			}
			it++;
		}
		cout << ans << endl;
	}
	return 0;
}
