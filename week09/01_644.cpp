#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string s;
	int t = 1;

	while (cin >> s) {
		vector<string> v;
		v.push_back(s);

		while (cin >> s, s[0]!='9') {
			v.push_back(s);
		}

		bool im = true;
		for (int i=0; i<v.size()-1; i++) {
			for (int j=i+1; j<v.size(); j++) {
				int m = min(v[i].size(), v[j].size());
				if (v[i].substr(0, m) == v[j].substr(0, m)) {
					im = false;
					break;
				}
			}
			if (!im) break;
		}

		cout << "Set " << t++ << " ";

		if (im) {
			cout << "is immediately decodable" << endl;
		} else {
			cout << "is not immediately decodable" << endl;
		}
	}

	return 0;
}
