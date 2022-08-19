#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

char map[50][50];
bool visited[50][50];
int direction[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

int main(int argc, char const* argv[])
{
	int R, C;
	cin >> R >> C;
	
	queue<pair<int, int>> water;
	queue<pair<int, int>> pos;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			visited[i][j] = false;
			cin >> map[i][j];
			if (map[i][j] == '*') water.push(make_pair(i, j));
			else if (map[i][j] == 'S') pos.push(make_pair(i, j));
		}
	}

	int time = 0;
	while (!pos.empty()) {
		time++;
		int q_size = pos.size();
		for (int i = 0; i < q_size; i++) {
			int pos_r = pos.front().first;
			int pos_c = pos.front().second;

			pos.pop();
			if (map[pos_r][pos_c] == '*') continue;
			for (int j = 0; j < 4; j++) {
				int after_r = pos_r + direction[j][0];
				int after_c = pos_c + direction[j][1];
				if (after_r >= 0 && after_r < R && after_c >= 0 && after_c < C) {
					if (map[after_r][after_c] == '.') {
						map[after_r][after_c] = 'S';
						pos.push(make_pair(after_r, after_c));
					}
					else if (map[after_r][after_c] == 'D') {
						cout << time << endl;
						return 0;
					}
				}
			}
		}

		q_size = water.size();
		for (int i = 0; i < q_size; i++) {
			int water_r = water.front().first;
			int water_c = water.front().second;
			water.pop();
			for (int j = 0; j < 4; j++) {
				int after_r = water_r + direction[j][0];
				int after_c = water_c + direction[j][1];
				if (after_r >= 0 && after_r < R && after_c >= 0 && after_c < C) {
					if (map[after_r][after_c] == '.' || map[after_r][after_c] == 'S') {
						map[after_r][after_c] = '*';
						water.push(make_pair(after_r, after_c));
					}
				}
			}
		}
	}
	
	cout << "KAKTUS" << endl;
	
	return 0;
}