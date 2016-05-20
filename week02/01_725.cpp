/*
  方針:
  あらかじめ0から9の数字の順列を用いて、
  計算されうる状態を全て列挙する。
  その際、計算元となる順列も保持しておく。
  入力に対して計算結果に基づく組み合わせを表示する。
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<pair<int, int> > ans[80];
vector<int> nums;

void initilize()
{
	do {
		int a = nums[0]*10000
			+ nums[1]*1000
			+ nums[2]*100
			+ nums[3]*10
			+ nums[4];

		int b = nums[5]*10000
			+ nums[6]*1000
			+ nums[7]*100
			+ nums[8]*10
			+ nums[9];

		if (a % b == 0) ans[a / b].push_back(make_pair(a, b));

	} while (next_permutation(nums.begin(), nums.end()));
}

int main()
{
	for (int i=0; i<10; i++) nums.push_back(i);
	initilize();

	int n, cnt = 0;
	while (cin >> n, n) {
		if (cnt++ > 0) cout << endl;

		if (ans[n].size() == 0) {
			printf("There are no solutions for %d.\n", n);
		} else {
			for (int i=0; i<ans[n].size(); i++) {
				printf("%05d / %05d = %d\n", ans[n][i].first, ans[n][i].second, n);
			}
		}
	}

	return 0;
}
