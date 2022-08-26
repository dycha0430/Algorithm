#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<char, int> m = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
string answer_str = "";
int answer = 0;

void make_str(string c, int num) {
	int count = 0;
	while (answer >= num && count < 3) {
		count++;
		answer_str += c;
		answer -= num;
	}
}

int main(int argc, char const* argv[])
{
	
	
	
	for (int num = 0; num < 2; num++) {
		string str;
		cin >> str;
		for (int i = 0; i < str.length(); i++) {
			if (i < str.length() - 1) {
				if (m[str[i]] < m[str[i+1]]) {
					answer += m[str[i + 1]] - m[str[i]];
					i++;
					continue;
				}
			}
			answer += m[str[i]];
		}
	}

	cout << answer << endl;
	make_str("M", 1000);
	make_str("CM", 900);
	make_str("D", 500);
	make_str("CD", 400);
	make_str("C", 100);
	make_str("XC", 90);
	make_str("L", 50);
	make_str("XL", 40);
	make_str("X", 10);
	make_str("IX", 9);
	make_str("V", 5);
	make_str("IV", 4);
	make_str("I", 1);

	cout << answer_str << endl;
	
	return 0;
}
