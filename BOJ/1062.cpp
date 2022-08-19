#include <iostream>
#include <math.h>
#include <string>
#include <memory.h>
#include <algorithm>

using namespace std;
typedef long long ll;

bool learned[26];
int N, K;
string words[50];
const int ALPHABET_NUM = 26;
int answer = 0;

void solve(int selected, int last_idx) {
	if (selected == K) {
		int tmp_answer = 0;
		for (int i = 0; i < N; i++) {
			bool possible = true;
			for (int j = 0; j < words[i].length(); j++) {
				if (!learned[words[i][j] - 'a']) {
					possible = false;
					break;
				}
			}
			if (possible) tmp_answer++;
 		}

		answer = max(answer, tmp_answer);
	}
	else if (last_idx >= ALPHABET_NUM-1) return;
	
	for (int i = last_idx+1; i < ALPHABET_NUM; i++) {
		if (learned[i]) continue;
		learned[i] = true;
		solve(selected + 1, i);
		learned[i] = false;
	}
}

int main(int argc, char const* argv[])
{
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		string word;
		cin >> word;
		words[i] = word.substr(4, word.length() - 8);
	}
	
	memset(learned, false, sizeof(bool) * 26);
	learned['a' - 'a'] = true;
	learned['c' - 'a'] = true;
	learned['t' - 'a'] = true;
	learned['n' - 'a'] = true;
	learned['i' - 'a'] = true;
	
	K -= 5;
	if (K < 0) {
		cout << "0";
		return 0;
	}

	solve(0, -1);
	cout << answer;	
	
	return 0;
}