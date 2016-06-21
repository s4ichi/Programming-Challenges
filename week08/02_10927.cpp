#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<ll, pair<int, pair<int, int> > > plii;
typedef pair<int, int> point;

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

bool comp(const point a, const point b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

int main()
{
	int t = 1;
	int n;
	while (cin >> n, n) {
		vector<plii> v(n);
		for (int i=0; i<n; i++) {
			int x, y, z;
			cin >> x >> y >> z;

			v[i].second.second.first = x;
			v[i].second.second.second = y;

			v[i].second.first = z + 1;
			v[i].first = (ll)x*(ll)x + (ll)y*(ll)y;
		}

		sort(v.begin(), v.end());

		vector<point> ans;
		map<point, int> memo;
		for (int i=0; i<n; i++) {
			int x = v[i].second.second.first, y = v[i].second.second.second, z = v[i].second.first;

			int g = gcd(abs(x), abs(y));
			if (x == 0) g = abs(y);
			else if (y == 0) g = abs(x);

			if (memo[make_pair(x/g, y/g)] >= z) {
				ans.push_back(v[i].second.second);
			} else {
				memo[make_pair(x/g, y/g)] = z;
			}
		}

		sort(ans.begin(), ans.end(), comp);
		int k = ans.size();

		cout << "Data set " << t++ << ":" << endl;

		if (k == 0) {
			cout << "All the lights are visible." << endl;
		} else {
			cout << "Some lights are not visible:" << endl;
			for (int i=0; i<k; i++) {
				cout << "x = " << ans[i].first << ", y = " << ans[i].second;

				if (i == k - 1) cout << "." << endl;
				else cout << ";" << endl;
			}
		}
	}

	return 0;
}
