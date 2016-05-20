#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/*
  方針:
  元の数列の前後で差を取得し、昇順でソートを行う。
  もしソート後の数列が整数における連続になっていた場合は"Jolly"を、
  連続で無かった場合には"Not jolloy"を出力する。
 */

int main()
{
	int n;
	while (cin >> n, n) {
		if(cin.eof()) break;
		vector<int> v(n), s;

		for (int i=0; i<n; i++) {
			cin >> v[i];
			if(i>0) s.push_back(abs(v[i-1] - v[i]));
		}

		sort(s.begin(), s.end());

		bool f = false;
		for (int i=0; i<s.size(); i++) {
			if(s[i] != i+1) {
				cout << "Not jolly" << endl;
				f = true;
				break;
			}
		}

		if(!f) cout << "Jolly" << endl;
	}

	return 0;
}
