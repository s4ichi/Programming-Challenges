#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<int> seq(n);
		for (int i=0; i<n; i++) {
			cin >> seq[i];
			seq[i] %= k;
			if (seq[i] < 0) seq[i] *= -1;
		}

		bool div[2][101];
		memset(div, 0, sizeof(div));

		div[0][0] = true;

		for (int i=0; i<n; i++) {
			for (int j=0; j<k; j++) {
				if(!div[i&1][j]) continue;
				div[(i+1)&1][(j+seq[i])%k] = true;
				div[(i+1)&1][(j-seq[i]+k)%k] = true;
				div[i&1][j] = false;
			}
		}

		if (div[n&1][0]) cout << "Divisible" << endl;
		else cout << "Not divisible" << endl;
	}

	return 0;
}
