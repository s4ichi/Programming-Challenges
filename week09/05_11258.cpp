#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <sstream>

using namespace std;
typedef long long ll;

//TLE
inline ll to_num(string s) {
	ll v;
	istringstream istr(s);
	istr>>v;
	if (v > INT_MAX) return -1;
	return v;
}

int to_num(string s, int st, int en)
{
	long long num = 0;

	for (int i=st; i<=en; i++) {
		num *= 10;
		num += s[i] - '0';
		if (num > INT_MAX) return -1;
	}

	return num;
}

int main()
{
	string d;
	ll dp[200][200];

	int t;
	cin >> t;
	while (t--) {
		memset(dp, 0, sizeof(dp));

		cin >> d;
		int n = d.size();

		for (int i=0; i<n; i++) {
			dp[i][i] = d[i] - '0';
		}

		for (int k=0; k<n; k++) {
			for (int i=0; i<n-k; i++) {
				//ll ma = to_num(d.substr(i, k+1));
				ll ma = to_num(d, i, i+k);
				for (int j=i; j<i+k; j++) {
					ma = max(ma, dp[i][j] + dp[j + 1][i + k]);
				}
				dp[i][i + k] = ma;
			}
		}

		cout << dp[0][n-1] << endl;
	}
	return 0;
}
