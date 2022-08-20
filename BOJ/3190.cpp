#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
int direction[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
int main(int argc, char const* argv[])
{
	int N, K, L;
	cin >> N >> K;
	int** map;
	map = new int* [N];
	for (int i = 0; i < N; i++) {
		map[i] = new int[N];
		for (int j = 0; j < N; j++) map[i][j] = 0;
	}

	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		map[b-1][a-1] = 1;
	}


	cin >> L;
	int curDirection = 1;
	int curTime = 1;

	map[0][0] = 2;
	queue<pair<int, int>> pos;
	pos.push({ 0, 0 });
	bool gameover = false;
	for (int i = 0; i < L; i++) {
		int X;
		char C;
		cin >> X >> C;
		
		
		for (int j = curTime; j <= X; j++) {
			int posX = pos.back().first + direction[curDirection][0];
			int posY = pos.back().second + direction[curDirection][1];

			if (posX >= N || posY >= N || posX < 0 || posY < 0) {
				gameover = true;
				break;
			}
			else if (map[posX][posY] == 2) {
				gameover = true;
				break;
			}
			else if (map[posX][posY] == 0) {
				map[pos.front().first][pos.front().second] = 0;
				pos.pop();
			}
			map[posX][posY] = 2;
			pos.push({ posX, posY });
			
			curTime++;
		}
		if (gameover) break;

		if (C == 'L') {
			curDirection = (curDirection + 3) % 4;
		}
		else {
			curDirection = (curDirection + 1) % 4;
		}
	}

	if (!gameover) {
		while (true) {
			int posX = pos.back().first + direction[curDirection][0];
			int posY = pos.back().second + direction[curDirection][1];

			if (posX >= N || posY >= N || posX < 0 || posY < 0) {
				break;
			}
			else if (map[posX][posY] == 2) {
				break;
			}
			else if (map[posX][posY] == 0) {
				map[pos.front().first][pos.front().second] = 0;
				pos.pop();
			}
			map[posX][posY] = 2;
			pos.push({ posX, posY });
			curTime++;
		}
	}
	cout << curTime << endl;

	return 0;
}