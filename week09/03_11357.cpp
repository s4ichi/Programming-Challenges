#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <numeric>

using namespace std;

int main() {
	int t;
	cin >> t;
	cin.ignore();

	while (t--) {
		string in;
		getline(cin, in);

		vector<string> f;
		for (int i=0; i<in.size(); i++) {
			int j = i + 1;
			while (in[j] != '|' && j<in.size()) j++;
			f.push_back(in.substr(i, j-i));
			i = j;
		}

		bool result;
		int var[256];

		for (int i=0; i<f.size(); i++) {
			int boolean = true;
			result = true;
			fill(var, var+256, -1);
			string cur = f[i];

			for (int j=1; j<cur.size()-1; j++) {
				if (cur[j] == '&') continue;

				if (cur[j] == '~') {
					boolean = false;
					j++;
				}

				if (var[cur[j]] == !boolean) {
					result = false;
					break;
				} else {
					var[cur[j]] = boolean;
				}

				boolean = true;
			}

			if (result) {
				break;
			}
		}

		if (result) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}
