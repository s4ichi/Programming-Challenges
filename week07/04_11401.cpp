#include <iostream>

using namespace std;
typedef long long ll;

int main()
{
	ll num[1000001];

	num[3] = 0;
	for (ll i=4; i<=1000000; i++) {
		num[i] = num[i-1] + ((i-1) * (i-2) / 2 - (i-1) / 2) / 2;
	}

	int n;
	while (cin >> n, n > 2) {
		cout << num[n] << endl;
	}

	return 0;
}
