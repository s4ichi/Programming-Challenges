#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;


int main(){
	const int N = 250;
	const int M = N*N;

	int t;
	cin >> t;
	for(int k=1; k<=t; k++){
		int n, a, b;
		cin >> n >> a >> b;

		int rank[M+1], dp[M+1];
		for (int i=0; i<=M; i++) {
			rank[i] = 1<<28;
			dp[i] = 1<<28;
		}

		vector<int> an(a+1), bn(b+1);

		for (int i=0; i<a+1; i++) {
			cin >> an[i];
			rank[an[i]] = i;
		}

		for (int i=0; i<b+1; i++) {
			cin >> bn[i];
			bn[i] = rank[bn[i]];
		}

		for (int i=0; i<b+1; i++) {
			*lower_bound(dp, dp+M+1, bn[i]) = bn[i];
		}

		int ans = 0;
		for (int i=0; i<=M; i++) {
			if (dp[i] < 1<<28) ans = i + 1;
		}

		cout << "Case " << k << ": " << ans << endl;
	}

	return 0;
}
