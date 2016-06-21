#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>

#define fi first
#define se second

using namespace std;

typedef pair<double, double> point;

double dist(point a, point b) {
	double x = a.fi - b.fi, y = a.se - b.se;
	return sqrt(x*x + y*y);
}

point circumcenter(point a, point b, point c) {
	double x1 = a.fi, y1 = a.se,
		x2 = b.fi, y2 = b.se,
		x3 = c.fi, y3 = c.se;

	double p = ((y1-y3)*(y1*y1 - y2*y2 + x1*x1 - x2*x2) - (y1-y2)*(y1*y1 - y3*y3 + x1*x1 - x3*x3)) / (2*(y1-y3)*(x1-x2)-2*(y1-y2)*(x1-x3));
	double q = ((x1-x3)*(x1*x1 - x2*x2 + y1*y1 - y2*y2) - (x1-x2)*(x1*x1 - x3*x3 + y1*y1 - y3*y3)) / (2*(x1-x3)*(y1-y2)-2*(x1-x2)*(y1-y3));

	return make_pair(p, q);
}

int main()
{
	int t = 1, n;
	while (cin >> n, n) {
		point a, b, c;
		cin >> a.fi >> a.se >> b.fi >> b.se >> c.fi >> c.se;

		point p = circumcenter(a, b, c), min_pos = a, max_pos = a;
		point prev = a, cur = a;

		double sint = sin(2*M_PI/n);
		double cost = cos(2*M_PI/n);

		for (int i=0; i<n; i++, prev = cur) {
			double dx = prev.fi - p.fi, dy = prev.se - p.se;

			cur.fi = p.fi + dx*cost - dy*sint;
			cur.se = p.se + dx*sint + dy*cost;

			min_pos.fi = min(min_pos.fi, cur.fi);
			min_pos.se = min(min_pos.se, cur.se);

			max_pos.fi = max(max_pos.fi, cur.fi);
			max_pos.se = max(max_pos.se, cur.se);
		}

		cout << "Polygon " << t++ << ": ";
		printf("%.3lf\n", fabs(max_pos.fi - min_pos.fi) * fabs(max_pos.se - min_pos.se));
	}

	return 0;
}
