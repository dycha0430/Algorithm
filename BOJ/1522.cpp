#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;

int main(int argc, char const* argv[])
{
	string str;
	cin >> str;

	int a_num = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'a') a_num++;
	}

	int b_num = 0;
	for (int i = 0; i < a_num; i++) {
		if (str[i] == 'b') b_num++;
	}
	int answer = b_num;
	for (int i = 1; i < str.length(); i++) {
		if (str[i - 1] == 'b') b_num--;
		if (str[(i - 1 + a_num) % str.length()] == 'b') b_num++;
		answer = min(answer, b_num);
	}

	cout << answer << endl;
	
	return 0;
}