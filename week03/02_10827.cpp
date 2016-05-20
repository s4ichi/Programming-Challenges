#include <iostream>
#include <algorithm>

#define N 75

using namespace std;

int main()
{
	int t;
	cin >> t;

	while (t--) {
		int n;
		int a2[N+1][N+1];
		int s4[2*N+1][2*N+1];

		cin >> n;
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				cin >> a2[i][j];
			}
		}

		for (int i=0; i<2*n; i++) {
			for (int j=0; j<2*n; j++) {
				s4[i+1][j+1] = s4[i][j+1] + s4[i+1][j] - s4[i][j] + a2[i%n][j%n];
			}
		}

		int ans = -1 * 1<<28;

		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				for (int k=1; k<=n; k++) {
					for (int l=1; l<=n; l++) {
						int val = s4[i+k][j+l] - s4[i][j+l] - s4[i+k][j] + s4[i][j];
						ans = max(ans, val);
					}
				}
			}
		}

		cout << ans << endl;
	}

	return 0;
}
