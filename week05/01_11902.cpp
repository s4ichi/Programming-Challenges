#include <iostream>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

int n;

void walk(bool *f, int cur, vector<int> *e, int ignore)
{
	if (f[cur]) return;
	if (ignore == cur) return;

	f[cur] = true;

	for (int i=0; i<e[cur].size(); i++) {
		walk(f, e[cur][i], e, ignore);
	}

	return;
}

int main()
{
	int cs;
	cin >> cs;

	for (int t=1; t<=cs; t++) {
		cin >> n;

		string line = "+";
		for (int i=0; i<n*2-1; i++) line += '-';
		line += '+';
		cout << "Case " << t << ":" << endl;
		cout << line << endl;

		vector<int> e[101];

		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				int in;
				cin >> in;
				if (in) e[i].push_back(j);
			}
		}

		bool root_f[n], f[n];
		memset(root_f, 0, sizeof(root_f));
		walk(root_f, 0, e, 101);

		for (int i=0; i<n; i++) {
			memset(f, 0, sizeof(f));
			walk(f, 0, e, i);

			cout << '|';
			for (int j=0; j<n; j++) {
				if (!f[j] && root_f[j]) {
					cout << "Y|";
				} else {
					cout << "N|";
				}
			}
			cout << endl << line << endl;
		}
	}

	return 0;
}
