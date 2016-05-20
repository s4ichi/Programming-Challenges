#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	cin >> t;

	for (int p=0; p<t; p++) {
		int n;
		cin >> n;

		bool nothing = true;
		int ma = 0, region = 0, st1 = 1, st2 = 1, en = 1, len = 0;

		for (int i=0; i<n-1; i++) {
			int v; cin >> v;

			region += v;
			len++;

			if (region < 0) {
				region = 0;
				len = 0;
				st1 = i + 2;
			}

			if (region > ma || region == ma && en - st2 < len) {
				nothing = false;
				en = i + 2;
				st2 = st1;
				ma = region;
			}
		}

		if (nothing) {
			cout << "Route " << p+1 << " has no nice parts" << endl;
		} else {
			cout << "The nicest part of route " << p+1 << " is between stops " << st2 <<  " and " << en << endl;;
		}
	}

	return 0;
}
