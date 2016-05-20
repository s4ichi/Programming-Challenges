/*
  方針:
  経路情報の入力に対して、シミュレート用のデータを生成する。
  必要なタンクの内容量は整数範囲内に収まらないかつ入力から逆算するのは効率が悪いため、
  十分な範囲を取った二分探索を用いて検証する。

  二分探索の各計算においてシミュレートを行い、到達可能か判断をする。
  到達可能であれば探索範囲を少ないへ縮め、到達不可能であれば多いほうへ縮める。
  最終的に探索範囲が収束するまで探索を行い、算出された答えを出力する。

  今回の場合は少数3桁までの出力であるため、
  収束条件は用いた 1e-9 よりも緩い制約であった場合においても計算可能であると考えられる。
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#define mp make_pair

using namespace std;

typedef pair<int, pair<int, int> > lot;

bool simulate(double init_tank, vector<lot> v)
{
	double tank = init_tank;
	int load = 0, leak = 0;
	double eff = 1.0;

	vector<lot>::iterator it = v.begin();
	while (it != v.end()) {
		lot cur = *it;
		int n = cur.second.first, m = cur.second.second;

		tank -= (n - load) * eff;
		tank -= (n - load) * leak;
		load = n;

		if(tank < 0.0) return false;

		if (cur.first == 1) {
			eff = (double)m / 100.0;

		} else if (cur.first == 2) {
			leak++;

		} else if (cur.first == 3) {
			leak = 0;

		} else if (cur.first == 4) {
			tank = init_tank;

		} else {
			break;
		}

		it++;
	}

	return true;
}

int main()
{
	string fuel, consumption;
	int n, m;
	while (1) {
		cin >> n >> fuel >> consumption >> m;
		if (!n && !m) break;

		//fuel: 1, leak: 2,, Mechanic: 3, Gas station: 4, goal: 5
		vector<lot> v;
		v.push_back(mp(1, mp(n, m)));

		while (1) {
			cin >> n >> fuel;

			if (fuel == "Fuel") {
				cin >> consumption >> m;
				v.push_back(mp(1, mp(n, m)));

			} else if (fuel == "Leak") {
				v.push_back(mp(2, mp(n, 0)));

			} else if (fuel == "Mechanic") {
				v.push_back(mp(3, mp(n, 0)));

			} else if (fuel == "Gas") {
				cin >> consumption;
				v.push_back(mp(4, mp(n, 0)));

			} else {
				v.push_back(mp(5, mp(n, 0)));
				break;
			}
		}

		double l = 0.0, r = 100000000.0, mid;

		while (r - l > 1e-9) {
			mid = (l + r) / 2.0;

			bool result = simulate(mid, v);
			if (result) {
				r = mid;
			} else {
				l = mid;
			}
		}

		printf("%.3lf\n", mid);
	}

	return 0;
}
