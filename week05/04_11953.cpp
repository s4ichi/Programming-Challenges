#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;
typedef pair<int, int> pii;

int n;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

void mapping(int y, int x, string *ma)
{
	ma[y][x] = '.';

	for (int i=0; i<4; i++) {
		int yy = y + dy[i];
		int xx = x + dx[i];
		if (yy >= n || yy < 0 || xx >= n || xx < 0) continue;

		if (ma[yy][xx] != '.') {
			mapping(yy, xx, ma);
		}
	}
}

int main()
{
	int cs;
	cin >> cs;

	for (int t=1; t<=cs; t++) {
		cin >> n;

		string ma[n];
		for (int i=0; i<n; i++) {
			cin >> ma[i];
		}

		int cnt = 0;
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if (ma[i][j] == 'x') {
					cnt++;
					mapping(i, j, ma);
				}
			}
		}

		cout << "Case " << t << ": " << cnt << endl;
	}

	return 0;
}
