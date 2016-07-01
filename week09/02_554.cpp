#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;


int main() {
	set<string> dict;
	string s, best;

	while (cin >> s, s[0] != '#') {
		dict.insert(s);
	}

	cin.ignore();
	getline(cin, s);
	int n = s.size(), ma = 0;

	for (int i=0; i<n; i++) {
		s[i] = (s[i] == ' ')?'@':s[i];
	}

	for (int k=0; k<27; k++){
		string tmp = s;

		for (int i=0; i<n; i++) {
			tmp[i] = '@' + (((tmp[i] - '@') + k) % 27);
		}

		int cnt = 0;
		for (int i=0; i<n; i++){
			int j = i;
			while (tmp[j] != '@' && j<n) j++;

			if (dict.find(tmp.substr(i, j-i)) != dict.end()) {
				cnt++;
			}
		}

		if (ma < cnt){
			ma = cnt;
			best = tmp;
		}
	}

	vector<string> term;
	for (int i=0; i<n; i++) {
		int j = i + 1;
		while (best[j] != '@' && j<n) j++;
		term.push_back(best.substr(i, j-i));
		i = j;
	}

	for (int i=0; i<term.size(); i++) {
		string buf = term[i];
		while ((buf+term[i+1]).length() < 60 && i+1<term.size()) {
			buf += " " + term[i+1];
			i++;
		}

		cout << buf << endl;;
	}

	return 0;
}
