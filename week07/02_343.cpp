#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>

#define DBG 0

using namespace std;

#define DUMP(x) if(DBG){cerr << #x << " = " << (x) << endl;}
inline int to_int(string s) {int v; istringstream istr(s);istr>>v;return v;}

int char_to_base[256];

int num_with_base(string num, int base)
{
	int res = 0, b = 1;
	for (int i=num.size()-1; i>=0; i--, b *= base) {
		res += char_to_base[num[i]] * b;
	}
	return res;
}

int main()
{
	for (int i=0; i<=9; i++) {
		char_to_base['0' + i] = i;
	}

	for (int i=0; i<26; i++) {
		char_to_base['A' + i] = i + 10;
	}

	string n, m;
	while (cin >> n >> m) {
		int max_digit_n = 1, max_digit_m = 1;
		for (int i=0; i<n.size(); i++) max_digit_n = max(max_digit_n, char_to_base[n[i]]);
		for (int i=0; i<m.size(); i++) max_digit_m = max(max_digit_m, char_to_base[m[i]]);

		bool ended = false;
		for (int i=max_digit_n+1; i<=36; i++) {
			for (int j=max_digit_m+1; j<=36; j++) {
				int nn = num_with_base(n, i);
				int mm = num_with_base(m, i);
				DUMP(i);
				DUMP(j);
				DUMP(nn);
				DUMP(mm);

				if (num_with_base(n, i) == num_with_base(m, j)) {
					cout << n << " (base " << i << ") = " << m << " (base " << j << ")" << endl;
					ended = true;
					break;
				}
			}
			if (ended) break;
		}

		if (!ended) {
			cout << n <<" is not equal to " << m << " in any base 2..36" << endl;
		}
	}

	return 0;
}
