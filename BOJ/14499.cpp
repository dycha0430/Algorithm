#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;
typedef long long ll;
int direction[4][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };

int N, M, x, y, K;
int map[20][20];
int square[6];

void roll(int dir) {
	int newSquare[6];
	for (int i = 0; i < 6; i++) newSquare[i] = square[i];
	if (dir == 1) {
		newSquare[0] = square[3];
		newSquare[2] = square[0];
		newSquare[3] = square[5];
		newSquare[5] = square[2];
	}
	else if (dir == 2) {
		newSquare[0] = square[2];
		newSquare[2] = square[5];
		newSquare[3] = square[0];
		newSquare[5] = square[3];
	}
	else if (dir == 3) {
		newSquare[0] = square[4];
		newSquare[1] = square[0];
		newSquare[4] = square[5];
		newSquare[5] = square[1];
	}
	else if (dir == 4) {
		newSquare[0] = square[1];
		newSquare[1] = square[5];
		newSquare[4] = square[0];
		newSquare[5] = square[4];
	}
	
	for (int i = 0; i < 6; i++) square[i] = newSquare[i];
	return;
}

void solve(int command) {
	int newX = x + direction[command - 1][0];
	int newY = y + direction[command - 1][1];
	if (newX < 0 || newY < 0 || newX >= N || newY >= M) return;
	x = newX, y = newY;
	roll(command);
	if (map[x][y] == 0) map[x][y] = square[5];
	else {
		square[5] = map[x][y];
		map[x][y] = 0;
	}

	cout << square[0] << endl;
}

int main(int argc, char const* argv[])
{
	cin >> N >> M >> x >> y >> K;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < 6; i++) square[i] = 0;
	
	for (int i = 0; i < K; i++) {
		int command;
		cin >> command;
		solve(command);
	}

	return 0;
}
