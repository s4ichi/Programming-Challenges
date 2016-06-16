#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

bool prime[101];
int cnt[101];

void calc_prime()
{
	for (int i=2; i<=100; i++) prime[i] = true;

	for (int i=2; i<=100; i++) {
		if (prime[i]) {
			for (int j=i*2; j<=100; j+=i) {
				prime[j] = false;
			}
		}
	}
}

void legendre(int n) {
	for (int i=2; i<=n; i++) {
		if (prime[i]) {
			for (int j=i; j<=n; j*=i) {
				cnt[i] += n/j;
			}
		}
	}
}

int main()
{
	calc_prime();

	int n, d;
	while (cin >> n >> d, n || d) {
		memset(cnt, 0, sizeof(cnt));
		legendre(n);

		for (int i=2; i<=n ;i++) {
			while (d%i == 0 && cnt[i] >= 0) {
				d /= i;
				cnt[i]--;
			}
		}

		if (d != 1) {
			cout << 0 << endl;
		} else {
			long long ans = 1;
			for (int i=2; i<=n; i++) {
				ans *= cnt[i] + 1;
			}
			cout << ans << endl;
		}
	}

	return 0;
}
