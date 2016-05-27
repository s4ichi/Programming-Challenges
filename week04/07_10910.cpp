#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

ll c[100][100];

void calc_combination(ll n) {
	for(int i=0; i<=n; i++){
		c[i][0] = 1;
		for(int j=1; j<=i; j++){
			c[i][j] = (c[i-1][j-1] + c[i-1][j]);
		}
	}
}

int main()
{
	int n;
	cin >> n;

	calc_combination(70);

	for (int i=0; i<n; i++) {
		int n, t, p;
		cin >> n >> t >> p;

		if (t-n*p < 0) cout << 0 << endl;
		else cout << c[n+(t-n*p)-1][n-1] << endl;
	}

	return 0;
}
