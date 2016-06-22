#include <iostream>
#include <cstdio>
#include <cmath>
#include <complex>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

typedef complex<double> point;

namespace std {
	bool operator < (const point& a, const point& b) {
		return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
	}
}

double cross(point a, point b) {
	return imag(conj(a)*b);
}

double dot(point a, point b) {
	return real(conj(a)*b);
}

int ccw(point a, point b, point c) {
	b -= a; c -= a;
	if (cross(b, c) > 0) return +1;
	if (cross(b, c) < 0) return -1;
	if (dot(b, c) < 0) return +2;
	if (norm(b) < norm(c)) return -2;
	return 0;
}

vector<point> convex_hull(vector<point> p) {
	int n = p.size(), k = 0;
	vector<point> ch(2*n);

	sort(p.begin(), p.end());

	for (int i=0; i<n; ch[k++] = p[i++]) {
		while (k >= 2 && ccw(ch[k-2], ch[k-1], p[i]) <= 0) --k;
	}

	for (int i=n-2, t=k+1; i>=0; ch[k++] = p[i--]) {
		while (k >= t && ccw(ch[k-2], ch[k-1], p[i]) <= 0) --k;
	}

	ch.resize(k-1);

	return ch;
}

double area2(vector<point> p) {
	double res = 0;

	for (int i=2; i<p.size(); i++) {
		res += fabs(cross(p[i-1] - p[0], p[i] - p[i-1]));
	}

	return res/2;
}


bool contains(vector<point> ps, point p) {
	bool in = false;
	int n = ps.size();

	for (int i=0; i<n; i++) {
		point a = ps[i]-p, b = ps[(i+1)%n]-p;

		if (imag(a) > imag(b)) {
			swap(a, b);
		}

		if (imag(a) <= 0 && 0 < imag(b)) {
			if (cross(a, b) < 0) in = !in;
		}

		if (cross(a, b) == 0 && dot(a, b) <= 0) {
			return true;
		}
	}

	return in;
}

int main()
{
	vector<vector<point> > kg;

	int t;
	while (cin >> t, t>=0) {
		vector<point> cur;

		for (int i=0; i<t; i++) {
			double a, b;
			cin >> a >> b;
			cur.push_back(point(a, b));
		}

		kg.push_back(convex_hull(cur));
	}

	bool f[21];
	memset(f, false, sizeof(f));

	double ans = 0, x, y;
	while (cin >> x >> y) {
		point m = point(x, y);

		for (int i=0; i<kg.size(); i++) {
			if (contains(kg[i], m) && !f[i]) {
				ans += area2(kg[i]);
				f[i] = true;
			}
		}
	}

	printf("%.2lf\n", ans);
	return 0;
}
