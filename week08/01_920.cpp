#include <cstdio>
#include <iostream>
#include <complex>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<double, double> point;

int main()
{
	int t, n;
	cin >> t;

	while (t--) {
		vector<point> v;

		cin >> n;
		for (int i=0; i<n; i++) {
			double x, y;
			cin >> x >> y;
			v.push_back(make_pair(x, y));
		}

		sort(v.begin(), v.end(), greater<point>());

		double h = 0, w = v[0].first, max_h = 0, sum = 0;
		for (int i=1; i<n; i++) {
			double x = v[i].first, y = v[i].second;
			if (max_h < y && y > v[i-1].second) {
				double dx = x - v[i-1].first, dy = y - v[i-1].second;
				double len = sqrt(dx*dx + dy*dy);
				sum += (y - max_h) * len / dy;
				max_h = y;
			}
		}

		printf("%.2lf\n", sum);
	}

	return 0;
}
