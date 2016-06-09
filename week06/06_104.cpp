#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>

#define EPS 1e-8

using namespace std;

int main()
{
	int n;

	while (scanf("%d", &n) != EOF) {
		double charge[25][25][25];
		int par[25][25][25];
		memset(charge, 0, sizeof(charge));

		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if (i == j) charge[i][j][0] = 1.0;
				else cin >> charge[i][j][0];

				par[i][j][0] = i;
			}
		}

		for (int s=1; s<n; s++) {
			for (int k=0; k<n; k++) {
				for (int i=0; i<n; i++) {
					for (int j=0; j<n; j++) {
						double tmp = charge[i][k][s-1] * charge[k][j][0];
						if (charge[i][j][s] < tmp) {
							charge[i][j][s] = tmp;
							par[i][j][s] = k;
						}
					}
				}
			}
		}

		bool printed = false;
		for (int s=1; s<n; s++) {
			for (int i=0; i<n; i++) {
				if (charge[i][i][s] > 1.01 + EPS) {
					printed = true;

					stack<int> path;
					int cur = par[i][i][s];
					path.push(cur);

					for(int j=1; j<=s; j++) {
						cur = par[i][path.top()][s-j];
						path.push(cur);
					}

					while (!path.empty()) {
						cout << path.top()+1 << " ";
						path.pop();
					}
					cout << i + 1 << endl;

					break;
				}
			}
			if (printed) break;
		}

		if (!printed) cout << "no arbitrage sequence exists" << endl;
	}

	return 0;
}
