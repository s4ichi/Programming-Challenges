#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string s;
	while(cin >> s) {
		string str = s;
		while (str[str.size()-1] != '#') {
			cin >> s;
			str += s;
		}

		long long bi = 0;
		for (int i=str.size()-2; i>=0; i--) {
			bi *= 2;
			bi = (bi + (str[i] - '0')) % 131071;
		}

		//cout << (bi & 131071) << endl;
		cout << (bi?"NO":"YES") << endl;
	}

	return 0;
}
