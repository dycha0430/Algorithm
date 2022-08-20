#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char const* argv[])
{
	string name;
	cin >> name;

	int alphabets[26];
	for (int i = 0; i < 26; i++) alphabets[i] = 0;
	for (int i = 0; i < name.length(); i++) {
		alphabets[name[i] - 'A']++;
	}

	int odd_num = 0;
	int odd_char;
	for (int i = 0; i < 26; i++) {
		if (alphabets[i] % 2 != 0) {
			odd_num++;
			odd_char = i;
		}
	}

	string answer = "";
	if (odd_num == 1) {
		answer += char(odd_char + 'A');
		alphabets[odd_char]--;
	}

	if (odd_num > 1) {
		cout << "I'm Sorry Hansoo" << endl;
	}
	else {
		for (int i = 25; i >= 0; i--) {
			for (int j = 0; j < alphabets[i] / 2; j++) {
				answer = char(i + 'A') + answer + char(i + 'A');
			}
		}
	}

	cout << answer << endl;
	return 0;
}