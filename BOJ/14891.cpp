#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int roll[4] = { 0, 0, 0, 0 };
int chain[4][8];
bool rolled[4] = { false, false, false, false };

void rolling(int c, int d) {
	rolled[c] = true;
	if (c - 1 >= 0 && rolled[c-1] == false) {
		if (chain[c][(6 - roll[c] + 800) % 8] != chain[c - 1][(2 - roll[c-1] + 800) % 8]) {
			rolling(c - 1, -1 * d);
		}
	}

	if (c + 1 < 4 && rolled[c + 1] == false) {
		if (chain[c][(2 - roll[c] + 800) % 8] != chain[c + 1][(6 - roll[c + 1] + 800) % 8]) {
			rolling(c + 1, -1 * d);
		}
	}

	roll[c] += d;
}

int main(int argc, char const* argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			char c;
			cin >> c;
			chain[i][j] = c - '0';
		}
	}

	// 각 톱니바퀴가 회전된 정도. 시계방향 회전 시 +1, 반시계 -1
	
	int K;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int c, d;
		cin >> c >> d;
		c--;
		for (int j = 0; j < 4; j++) rolled[j] = false;
		rolling(c, d);
	}

	int answer = 0;
	if (chain[0][(800 - roll[0]) % 8]) answer += 1;
	if (chain[1][(800 - roll[1]) % 8]) answer += 2;
	if (chain[2][(800 - roll[2]) % 8]) answer += 4;
	if (chain[3][(800 - roll[3]) % 8]) answer += 8;

	cout << answer << endl;

	return 0;
}

