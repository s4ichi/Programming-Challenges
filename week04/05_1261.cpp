#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, bool> memo;

bool popping(string s) {
	if (s.empty()) return true;
	if (memo.find(s) != memo.end()) return memo[s];

	for (int i=0; i<s.size(); i++) {
		int j = i;
		while (s[i] == s[j]) {
			if (j >= s.size()) break;
			if (j - i >= 1) {
				bool res = popping(s.substr(0, i) + s.substr(j+1));
				if(res) return memo[s] = true;
			}
			j++;
		}
		i = j-1;
	}

	return memo[s] = false;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;
		memo.clear();
		cout << popping(s) << endl;
	}

	return 0;
}
