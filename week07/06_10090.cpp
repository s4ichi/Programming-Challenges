#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

ll extgcd(ll a, ll b, ll &x, ll &y) {
	ll g = a; x = 1; y = 0;

	if (b) {
		g = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}

	return g;
}

int main()
{
	int n;
	while (cin >> n, n) {
		ll c1, n1, c2, n2, x, y;
		cin >> c1 >> n1 >> c2 >> n2;

		ll g = extgcd(n1, n2, x, y);

		ll low = ceil(-1.0 * x * n / n2);
		ll high = floor(1.0 * y * n / n1);

		if (n % g != 0 || low > high) {
			cout << "failed" << endl;
			continue;
		}

		n /= g;
		n1 /= g;
		n2 /= g;

		ll x1 = x * n;
		ll y1 = y * n;

		if (c1 * n2 > c2 * n1) {
			cout << (x1 + n2 * low) << " " << (y1 - n1 * low) << endl;
		} else {
			cout << (x1 + n2 * high) << " " << (y1 - n1 * high) << endl;
		}
	}

	return 0;
}
