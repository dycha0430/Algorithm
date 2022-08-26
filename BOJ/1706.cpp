#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main(int argc, char const* argv[])
{
	int R, C;
	cin >> R >> C;
	string puzzle[20];
	for (int i = 0; i < R; i++) {
		cin >> puzzle[i];
	}

	vector<string> v;

	// 가로낱말 찾기
	for (int i = 0; i < R; i++) {
		string word = "";
		for (int j = 0; j < C; j++) {
			if (puzzle[i][j] != '#') {
				word += puzzle[i][j];
			}
			else {
				if (word.length() > 1) {
					v.push_back(word);
					word = "";
				}
				else {
					word = "";
				}
			}
		}
		if (word.length() > 1) v.push_back(word);
	}

	for (int j = 0; j < C; j++) {
		string word = "";
		for (int i = 0; i < R; i++) {
			if (puzzle[i][j] != '#') {
				word += puzzle[i][j];
			}
			else {
				if (word.length() > 1) {
					v.push_back(word);
					word = "";
				}
				else {
					word = "";
				}
			}
		}
		if (word.length() > 1) v.push_back(word);
	}

	sort(v.begin(), v.end());
	cout << v[0] << endl;
	return 0;
}