#include <iostream>
#include <math.h>
#include <string>

using namespace std;
typedef long long ll;

string to_binary(ll num) {
	string s = "";
	while (num > 0) {
		if (num % 2) s = "1" + s;
		else s = "0" + s;
		num >>= 1;
	}

	return s;
}

ll to_num(string str) {
	ll num = 0;
	for (ll i = 0; i < str.length(); i++) {
		if (str[str.length() - 1 - i] == '1') num += powl(2, i);
	}

	return num;
}


int main(int argc, char const* argv[])
{
	ll X, K;
	cin >> X >> K;
	string binX = to_binary(X);
	string binK = to_binary(K);
	string binY = "";
	
	ll posX = binX.length()-1, posK = binK.length()-1;
	while (posK >= 0) {
		if (posX < 0 || binX[posX] == '0') {
			binY = binK[posK--] + binY;
		}
		else {
			binY = "0" + binY;
		}
		posX--;
	}

	cout << to_num(binY) << endl;
	
	return 0;
}