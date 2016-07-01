#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main() {
	string s;
	while (cin >> s, s[0] != '.') {
		int n = s.size(), i = 2, j = 0;

		vector<int> dp(n+1);
		dp[0] = dp[1] = 0;

		while(i==0 || s[i-1]) {
			if(s[i-1] == s[j]) {
				dp[i++] = ++j;
			} else if(j>0) {
				j = dp[j];
			} else {
				dp[i++] = 0;
			}
		}

		cout << n / (n - dp[n]) << endl;
	}
	return 0;
}
