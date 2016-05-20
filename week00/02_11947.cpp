#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int toInt(string s)
{
	int v;
	istringstream istr(s);
	istr>>v;
	return v;
}

bool is_uruu(int y)
{
	if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))
	   return true;
	else
	   return false;
}

int main()
{
	int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31 };

	int n;
	cin >> n;

	for (int i=0; i<n; i++) {
		string s;
		cin >> s;

		int day = toInt(s.substr(2, 2));
		int month = toInt(s.substr(0, 2));
		int year = toInt(s.substr(4, 4));

		// days[] : 各月の日付を表す
		// is_uruu: うるう年の判定
		// toInt  : 入力文字列を数値化

		// 上記のリソースを用いて40週 * 7日の日数をインクリメントし結果を表示する
		// "month * 100 + day" の形式によって星座の比較を演算子を用いて簡易化する

		for (int j=0; j<40*7; j++) {
			if (is_uruu(year) && month == 2 && day == 29) {
				month = 3;
				day = 1;
				continue;
			}

			if (day == days[month]) {
				if (is_uruu(year) && month == 2) j++;
				day = 0;
				month++;

				if (month == 13) {
					month = 1;
					year++;
				}
			}
			day++;
		}

		printf("%d %02d/%02d/%04d ", i+1, month, day, year % 10000);

		int date = month * 100 + day;

		if (date <= 120) {
			cout << "capricorn";

		} else if (date <= 219) {
			cout << "aquarius";

		} else if (date <= 320) {
			cout << "pisces";

		} else if (date <= 420) {
			cout << "aries";

		} else if (date <= 521) {
			cout << "taurus";

		} else if (date <= 621) {
			cout << "gemini";

		} else if (date <= 722) {
			cout << "cancer";

		} else if (date <= 821) {
			cout << "leo";

		} else if (date <= 923) {
			cout << "virgo";

		} else if (date <= 1023) {
			cout << "libra";

		} else if (date <= 1122) {
			cout << "scorpio";

		} else if (date <= 1222) {
			cout << "sagittarius";

		} else {
			cout << "capricorn";
		}
		cout << endl;
	}

	return 0;
}
