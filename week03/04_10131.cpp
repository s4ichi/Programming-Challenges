#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define mp make_pair

using namespace std;

typedef pair<int, pair<int, int> > pii;

int main()
{
	int n, m, N = 0;
	vector<pii> v;

	while (scanf("%d %d", &n, &m) != EOF) {
		N++;
		v.push_back(mp(m, mp(n, N)));
	}

	sort(v.begin(), v.end(), greater<pii>());

	vector<int> dp(N+1), ret(N+1), out;
	dp[0] = 1;

	for (int i=0; i<N; i++) {
		int ma = 0, idx = 0;

		for (int j=0; j<i; j++) {
			int iq = v[i].first, iw = v[i].second.first;
			int jq = v[j].first, jw = v[j].second.first;

			if (iw > jw && iq < jq && ma < dp[j]) {
				ma = dp[j];
				idx = j;
			}

			dp[i] = ma + 1;

			if (ma == 0) ret[i] = i;
			else ret[i] = idx;
		}
	}

	int top = 0, idx;
	for (int i=0; i<N; i++) {
		if (top < dp[i]) {
			idx = i;
			top = dp[i];
		}
	}

	while (1) {
		out.push_back(v[idx].second.second);
		if (idx == ret[idx]) break;
		idx = ret[idx];
	}

	cout << out.size() << endl;
	for (int i=out.size()-1; i>=0; i--) {
		cout << out[i] << endl;
	}

	return 0;
}
