#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;
const int MAX = 1000001;
int cache[MAX];

int canWin(string num) {
	int& ret = cache[stoi(num)];
	if (ret != MAX) return ret;

	for (int i = 0; i < num.length(); i++) {
		if (num[i] == '0') continue;
		for (int j = 1; j <= num.length() - i; j++) {
			int sub_num = stoi(num.substr(i, j));
			int res_num = stoi(num) - sub_num;
			if (res_num == 0) continue;
			if (canWin(to_string(res_num)) == -1) ret = min(ret, sub_num);
		}
	}
	
	if (ret == MAX) ret = -1;
	return ret;
}
int main(int argc, char const* argv[])
{
	string N;
	cin >> N;
	for (int i = 0; i <= stoi(N); i++) cache[i] = MAX;

	cout << canWin(N);

	return 0;
}
