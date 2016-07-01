#include <iostream>
#include <string>


using namespace std;

int idx = 0;

int read_int(string e) {
	int res = 0;

	int mul = 1;
	if (e[idx] == '-'){
		idx++;
	    mul = -1;
	}

	string buf = "";
	while (isdigit(e[idx])) {
		buf += e[idx];
		idx++;
	}

	for (int i=0; i<buf.size(); i++) {
		res *= 10;
		res += buf[i] - '0';
	}

	return res * mul;
}

double read_float(string e) {
	double integral = read_int(e), decimal = 0.0;

	if (e[idx] == '.') idx++;
	else return integral;

	string buf = "";
	while (isdigit(e[idx])) {
		buf += e[idx];
		idx++;
	}

	for (int i=buf.size()-1; i>=0; i--) {
		decimal /= 10;
		decimal += (double)(buf[i] - '0') / 10;
	}

	return integral + decimal;
}

double eval(string e) {
	if (e[idx] == '(') {
		idx++; // (
		double p = read_float(e);
		idx++; // ws
		double x = eval(e);
		idx++; // ws
		double y = eval(e);
		idx++; // )

		return p * (x + y) + (1 - p) * (x - y);
	} else {
		return read_float(e);
	}
}

int main() {
	string s;
	while (getline(cin, s), s[1] != ')' ) {
		idx = 0;
		printf("%.2lf\n", eval(s));
	}
	return 0;
}
