#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	cin >> t;

	for(; t>0; t--) {
		int a, b;
		cin >> a >> b;

		if(a > b) {
			cout << ">";
		} else if (a < b) {
			cout << "<";
		} else {
			cout << "=";
		}
		cout << endl;
	}

	return 0;
}
