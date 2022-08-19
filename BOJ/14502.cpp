#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int map[8][8];
int new_virus = 100;
int direction[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

void solve(int i, int j, int k) {
	int _map[8][8];
	queue<pair<int, int>> q;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			_map[r][c] = map[r][c];
			if (map[r][c] == 2) q.push({ r, c });
		}
	}
	_map[i / M][i % M] = 1;
	_map[j / M][j % M] = 1;
	_map[k / M][k % M] = 1;

	int ret = 0;

	while (!q.empty()) {
		int row = q.front().first;
		int col = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int row2 = row + direction[dir][0];
			int col2 = col + direction[dir][1];
			if (row2 < 0 || col2 < 0 || row2 >= N || col2 >= M) continue;
			else if (_map[row2][col2] == 0) {
				_map[row2][col2] = 2;
				q.push({ row2, col2 });
				ret++;
			}
		}
		if (ret >= new_virus) break;
	}

	new_virus = min(new_virus, ret);
	
}
int main(int argc, char const* argv[])
{
	cin >> N >> M;
	
	int safe = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) safe++;
		}
	}

	int total = N * M;
	for (int i = 0; i < total-2; i++) {
		if (map[i / M][i % M] != 0) continue;
		for (int j = i + 1; j < total - 1; j++) {
			if (map[j / M][j % M] != 0) continue;
			for (int k = j + 1; k < total; k++) {
				if (map[k / M][k % M] != 0) continue;
				solve(i, j, k);
			}
		}
	}

	cout << safe - new_virus - 3 << endl;
	return 0;
}