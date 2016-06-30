#include <iostream>
#include <string>
#include <numeric>

using namespace std;

struct Trie {
	int value;
	Trie *next[0x100];

	Trie() {
		fill(next, next+0x100, (Trie*)0);
	}
};

void add(string s, Trie *r) {
	for (int i = 0; s.size(); ++i) {
		char c = s[i];
		if (!r->next[c]) r->next[c] = new Trie;
		r = r->next[c];
	}

	return r;
}

Trie *find(string s, Trie *r) {
	for (int i = 0; s.size(); ++i) {
		char c = s[i];
		if (!r->next[c]) return false;
		r = r->next[c];
	}

	return true;
}

int main() {
	Trie t;

	int m = 0;
	string s;
	while (cin >> s, s[0] != '#') {
		add(s, t);
		m = max(m, s.size());
	}

	string cy = "";
	while (cin >> s) {
		cy += s;
	}

	for (int k=1; k<26; k++) {
		for (int i=0; i<cy.size()-m; i++) {
			s = "";
			for (int j=0; j<m; j++) {
				s += (cy[i+j] + k) % 27;
			}
		}
	}

	return 0;
}
