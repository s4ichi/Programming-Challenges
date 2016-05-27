#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
	const int N = 10000;
	vector<int> dp(N+1, INT_MAX/2);

	for (int i=1; i*i<=N; i++) dp[i*i] = 1;
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=i; j++) {
			dp[i] = min(dp[i], dp[j] + dp[i-j]);
		}
	}

	int t, n;
	cin >> t;

	while (t--) {
		cin >> n;
		cout << dp[n] << endl;
	}

	return 0;
}
