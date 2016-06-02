#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <numeric>
#include <string>
#include <sstream>
#include <cstring>

using namespace std;

inline int toInt(string s) {int v; istringstream istr(s);istr>>v;return v;}
typedef pair<int, int> pii;

int dx[]={0,-1,0,1,1,1,-1,-1};
int dy[]={1,0,-1,0,1,-1,1,-1};

int main()
{
	int t;
	cin >> t;
	cin.ignore();

	while (t--) {
		int h, w, idx = 0;

		string ma[100];
		while (cin >> ma[idx], ma[idx][0] == 'L' || ma[idx][0] == 'W') idx++;

		h = idx; w = ma[0].size();

		vector<pii> input;
		int a = toInt(ma[idx]), b;
		cin >> b;
		input.push_back(make_pair(a-1, b-1));

		string buf;
		cin.ignore();

		while (1) {
			getline(cin, buf);
			if (buf == "\0") break;
			istringstream istr(buf);
			istr >> a >> b;
			input.push_back(make_pair(a-1, b-1));
		}

		for (int i=0; i<input.size(); i++) {
			a = input[i].first; b = input[i].second;

			if (ma[a][b] != 'W' || a >= h || a < 0 || b >= w || b < 0) {
				cout << 0 << endl;
				continue;
			}

			bool f[100][100];
			memset(f, false, sizeof(f));
			f[a][b] = true;

			queue<pii> q;
			q.push(make_pair(a, b));

			int cnt = 1;
			while (!q.empty()) {
				pii cur = q.front(); q.pop();

				for (int j=0; j<8; j++) {
					int y = cur.first + dy[j];
					int x = cur.second + dx[j];

					if (y >= h || y < 0 || x >= w || x < 0) continue;

					if (!f[y][x] && ma[y][x] == 'W') {
						cnt++;
						f[y][x] = true;
						q.push(make_pair(y, x));
					}
				}
			}
			cout << cnt << endl;

		}
		if (t>0) cout << endl;
	}

	return 0;
}
