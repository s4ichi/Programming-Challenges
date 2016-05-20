#include <iostream>

using namespace std;

int main()
{
	int k;
	while (cin >> k, k){
		int base_x, base_y;
		cin >> base_x >> base_y;

		// base_xとbase_yを用いて入力座標の基底を0にする
		// 問題に対して簡略化を行い、小さなミスを防ぐ

		for (int i=0; i<k; i++) {
			int x, y;
			cin >> x >> y;
			x -= base_x;
			y -= base_y;

			if(!x || !y) {
				cout << "divisa" << endl;
				continue;
			}

			if (y > 0) cout << "N";
			else if (y < 0) cout << "S";

			if (x > 0) cout << "E";
			else if (x < 0) cout << "O";

			cout << endl;
		}
	}

	return 0;
}
