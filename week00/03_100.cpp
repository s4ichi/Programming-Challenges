#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<int, int> memo;

// count(n, sum) : コラッツ問題におけるnの反復回数を測定する関数

// sumを引数にすることでコンパイラによる末尾最適化を期待する
// (UVA Online Judge では c++11のコンパイルオプションにO3が付くため)

int count(int n, int sum)
{
	if (n == 1) return sum;

	if (n & 1) {
		return count(3 * n + 1, sum + 1);
	} else {
		return count(n / 2, sum + 1);
	}
}

int main()
{
	int a, b;
	while (cin >> a >> b) {
		cout << a << " " << b << " ";

		if(a > b) swap(a, b);

		int ans = 0;
		for (int i=a; i<=b; i++) {
			ans = max(ans, count(i, 1));
		}

		cout << ans << endl;
	}
}
