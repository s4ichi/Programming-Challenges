#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <set>
#include <map>

using namespace std;

/*
  問題の規定より、解いた問題数と時間と番号をキーとしてソートを行う問題と解釈ができる。
  よって標準のsort関数に上記条件のoperatorを引数とすることで解答の出力が可能になる。
 */

struct Team {
	int number, time;
	map<int, int> penalty;
	set<int> solved;
	bool active;

	Team(int n) {
		this->active = false;
		this->number = n;
		this->time = 0;
	}

	void activate() {
		this->active = true;
	}

	bool is_solved(int p) {
		set<int>::iterator it;
		it = this->solved.find(p);
		return it != this->solved.end();
	}

	void AC(int p, int t) {
		this->solved.insert(p);
		this->time += 20 * this->penalty[p] + t;
	}

	void WA(int p) {
		this->penalty[p]++;
	}

	int count() {
		return this->solved.size();
	}

	bool operator <(const Team& o) const {
		int o_size = o.solved.size(), t_size = this->solved.size();
		if (o_size != t_size) {
			return (o_size < t_size);
		} else if (o.time != this->time) {
			return (o.time > this->time);
		} else {
			return (o.number > this->number);
		}
	}
};


int main()
{
	int n;
	string s;

	cin >> n;
	cin.ignore();
	getline(cin, s);

	stringstream ss;

	for (int w=0; w<n; w++) {
		if (w > 0) cout << endl;

		vector<Team> team;
		for (int i=0; i<=100; i++) {
			team.push_back(Team(i));
		}

		int a, p, t;
		char state;
		while (getline(cin, s)) {
			if (s.empty()) break;
			ss.clear();
			ss << s;
			ss >> a >> p >> t >> state;

			team[a].activate();
			if (state == 'C') {
				if (team[a].is_solved(p)) continue;
				team[a].AC(p, t);
			} else if (state == 'I') {
				team[a].WA(p);
			}
		}

		sort(team.begin(), team.end());

		vector<Team>::iterator it = team.begin();
		while (it != team.end()) {
			if (it->active == false){
				it++;
				continue;
			}
			cout << it->number << " " << it->count() << " " << it->time << endl;
			it++;
		}
	}
	return 0;
}
