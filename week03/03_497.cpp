#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#define DUMP(x)  cerr << #x << " = " << (x) << endl;

using namespace std;

inline int to_int(string s) {int v; istringstream istr(s);istr>>v;return v;}

int main()
{
	int t;
	scanf("%d\n", &t);

	while (t--) {
		vector<int> v;
		string in;
		while (getline(cin, in)) {
			if (!in.size()) break;
			v.push_back(to_int(in));
		}

		int n = v.size();
		vector<int> dp(n+1);
		vector<int> ret(n+1);
		ret[0] = 0;
		dp[0] = 1;

		for (int i=1; i<n; i++) {
			int ma = 0, idx = 0;
			for (int j=0; j<i; j++) {
				if (v[j] < v[i] && ma < dp[j]) {
					ma = dp[j];
					idx = j;
				}
			}
			dp[i] = ma + 1;
			if (ma == 0) ret[i] = i;
			else ret[i] = idx;
		}

		vector<int> out;

		int top = 0, idx;
		for (int i=0; i<n; i++) {
			if (top < dp[i]) {
				idx = i;
				top = dp[i];
			}
		}

		while (1) {
			out.push_back(v[idx]);
			if (idx == ret[idx]) break;
			idx = ret[idx];
		}

		sort(out.begin(), out.end());

		cout << "Max hits: " << out.size() << endl;
		for (int i=0; i<out.size(); i++) {
			cout << out[i] << endl;
		}
		if (t > 0) cout << endl;
	}

	return 0;
}
