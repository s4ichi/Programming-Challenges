#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

double rad(double c) {
	return c * M_PI / 180;
}

int main()
{
	double l, w, h, t;
	while (cin >> l >> w >> h >> t) {
		double tan_t = tan(rad(t));
		double full = l * h * w;

		double ans;
		if (tan_t < h / l) {
		    ans = full - w * 0.5 * l * l * sin(rad(t)) * sin(rad(90)) / sin(rad(t+90));
		} else {
			ans = w * 0.5 * h * h * sin(rad(90-t)) * sin(rad(90)) / sin(rad(t));

		}
		printf("%.3lf mL\n", ans);
	}

	return 0;
}
