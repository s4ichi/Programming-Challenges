#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

typedef pair<double, double> point;

const point o = make_pair(0, 0);

double dist(point a, point b) {
	double x = a.first - b.first, y = a.second - b.second;
	return sqrt(x*x + y*y);
}

double dots(point a, point b) {
	return  a.first * b.first + a.second * b.second;
}

bool is_border(point a, point b, double r) {
	point ab = make_pair(b.first - a.first, b.second - a.second);
	point oa = make_pair(-a.first, -a.second);

	double dot1 = dots(ab, oa);

	if (dot1 < 0) {
		return dist(a, o) < r;
	}

	double dot2 = dots(ab, ab);

	if (dot1 > dot2) {
		double len = dist(b, o);
		return len* len < r * r;
	} else {
		double dot3 = dots(oa, oa);
		return (dot3 - (dot1/dot2)*dot1) < r*r;
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--) {
		point a, b;
		double r;

		cin >> a.first >> a.second >> b.first >> b.second >> r;

		double st = dist(a, b);
		double ans = st;

		if (is_border(a, b, r)) {
			double da = dist(a, o);
			double db = dist(b, o);

			double td = sqrt(da * da - r * r) + sqrt(db * db - r * r);
			double len = acos((da * da + db * db - st * st) / (2.0 * da * db)) - acos(r / da) - acos(r / db);

			ans = td + len * r;
		}

		printf("%.3lf\n", ans);
	}

	return 0;
}
