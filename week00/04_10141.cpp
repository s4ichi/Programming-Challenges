#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n, p;
	int t = 1;

	// 入力において必要なものはn, p
	// そして各proposal name, price, num of met, であるため、
	// それ以外の入力は全て受け流す
	// また、名前関係の入力はスペースを含むので行単位で入力を受け取る

	// 各proposalにおいて問題中で定められたcomplianceを計算する
	// complianceが同値の場合、入力のpiceが小さいものを答えとして代入する

	while (scanf("%d %d\n", &n, &p), n && p) {
		if (t > 1) cout << endl;

		string s;

		double price;
		int num;

		string ans_name;
		double ans_cost = -1.0;
		double ans_comp = -1.0;

		for (int i=0; i<n; i++) getline(cin, s);

		for (int i=0; i<p; i++) {
			getline(cin, s);

			scanf("%lf %d\n", &price, &num);

			double comp = (double)num / (double)p;
			if (comp > ans_comp || ans_comp == -1.0 || ans_comp == comp && price < ans_cost) {
				ans_name = s;
				ans_cost = price;
				ans_comp = comp;
			}

			for (int j=0; j<num; j++) getline(cin, s);
		}

		cout << "RFP #" << t++ << endl << ans_name << endl;
	}

	return 0;
}
