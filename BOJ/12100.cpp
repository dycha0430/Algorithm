#include <iostream>
#include <algorithm>

using namespace std;

int answer = 0;
int N;
void solve(int cnt, int board[][20]) {

	if (cnt == 5) {
		// 최댓값 구하기
		int ret = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ret = max(ret, board[i][j]);
			}
		}
		
		answer = max(answer, ret);
		return;
	}
	int _board[20][20];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) _board[i][j] = board[i][j];
	}

	// up
	for (int j = 0; j < N; j++) {
		bool merge_possible = true;
		for (int k = 1; k < N; k++) {
			if (_board[k][j] == 0) continue;
			int pos = k;
			while (pos > 0 && _board[pos - 1][j] == 0) pos--;
			if (pos != k) {
				_board[pos][j] = _board[k][j];
				_board[k][j] = 0;
			}
			
			if (pos == 0) continue;
			if (!merge_possible) {
				merge_possible = true;
				continue;
			}
			if (_board[pos][j] == _board[pos - 1][j]) {
				_board[pos - 1][j] *= 2;
				_board[pos][j] = 0;
				merge_possible = false;
			}
		}
	}
	solve(cnt + 1, _board);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) _board[i][j] = board[i][j];
	}
	// down
	for (int j = 0; j < N; j++) {
		bool merge_possible = true;
		for (int k = N - 2; k >= 0; k--) {
			if (_board[k][j] == 0) continue;
			int pos = k;
			while (pos < N - 1 && _board[pos + 1][j] == 0) pos++;
			if (pos != k) {
				_board[pos][j] = _board[k][j];
				_board[k][j] = 0;
			}

			if (pos == N-1) continue;
			if (!merge_possible) {
				merge_possible = true;
				continue;
			}
			if (_board[pos][j] == _board[pos + 1][j]) {
				_board[pos + 1][j] *= 2;
				_board[pos][j] = 0;
				merge_possible = false;
			}
		}
	}
	solve(cnt + 1, _board);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) _board[i][j] = board[i][j];
	}
	// left
	for (int j = 0; j < N; j++) {
		bool merge_possible = true;
		for (int k = 1; k < N; k++) {
			if (_board[j][k] == 0) continue;
			int pos = k;
			while (pos > 0 && _board[j][pos - 1] == 0) pos--;
			if (pos != k) {
				_board[j][pos] = _board[j][k];
				_board[j][k] = 0;
			}

			if (pos == 0) continue;
			if (!merge_possible) {
				merge_possible = true;
				continue;
			}
			if (_board[j][pos] == _board[j][pos - 1]) {
				_board[j][pos - 1] *= 2;
				_board[j][pos] = 0;
				merge_possible = false;
			}
		}
	}
	solve(cnt + 1, _board);


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) _board[i][j] = board[i][j];
	}
	// right
	for (int j = 0; j < N; j++) {
		bool merge_possible = true;
		for (int k = N - 2; k >= 0; k--) {
			if (_board[j][k] == 0) continue;
			int pos = k;
			while (pos < N - 1 && _board[j][pos + 1] == 0) pos++;
			if (pos != k) {
				_board[j][pos] = _board[j][k];
				_board[j][k] = 0;
			}

			if (pos == N-1) continue;
			if (!merge_possible) {
				merge_possible = true;
				continue;
			}
			if (_board[j][pos] == _board[j][pos + 1]) {
				_board[j][pos + 1] *= 2;
				_board[j][pos] = 0;
				merge_possible = false;
			}
		}
	}
	solve(cnt + 1, _board);
}
int main(int argc, char const* argv[])
{
	cin >> N;
	int board[20][20];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> board[i][j];
	}

	solve(0, board);
	cout << answer << endl;

	return 0;
}