#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

int sum;
int cars[2001];
int dp[2001][10001];

void out_result(int idx, int w)
{
	if (dp[idx][w] < 2) return;

	if (dp[idx][w] == 2) {
		out_result(idx - 1, w - cars[idx]);
		cout << "starboard" << endl;
	} else {
		out_result(idx - 1, w);
		cout << "port" << endl;
	}

	return;
}

int main()
{
	int t;
	scanf("%d\n", &t);

	while (t--) {
		int len;
		cin >> len;
		len *= 100;

		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;

		int last_i = 0, last_j = 0;

		int idx = 1;
		sum = 0;

		while (cin >> cars[idx], cars[idx]) {
			for (int i=0; i<=len; i++) {
				if (!dp[idx - 1][i]) continue;

				// left
				if (cars[idx] + i <= len) {
					dp[idx][i + cars[idx]] = 2;
					last_i = idx;
					last_j = i + cars[idx];
				}

				// right
				if ((sum - i + cars[idx]) <= len) {
					dp[idx][i] = 3;
					last_i = idx;
					last_j = i;
				}
			}
			sum += cars[idx];
			idx++;
		}

		cout << last_i << endl;
		out_result(last_i, last_j);
		if (t > 0) cout << endl;
	}

	return 0;
}
