#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int direction[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int N, M;
pair<int, int> posO;
char board[10][10];

void solve(int firstPosR, int firstPosB) {
	queue<pair<int, pair<int, int>>> q;
	q.push({ 0, {firstPosR, firstPosB} });
	
	int solved = -1;
	while (!q.empty()) {
		pair<int, int> posR = { q.front().second.first / M, q.front().second.first % M };
		pair<int, int> posB = { q.front().second.second / M, q.front().second.second % M };
		int cnt = q.front().first;
		q.pop();
		if (cnt > 10) break;
		if (posR == posO && posB != posO) {
			solved = cnt;
			break;
		}
		else if (posB == posO) {
			continue;
		}

		pair<int, int> newPosR, newPosB;
		for (int i = 0; i < 4; i++) {
			newPosR = posR, newPosB = posB;
			bool releaning = false;
			while (true) {
				int nextI = newPosR.first + direction[i][0];
				int nextJ = newPosR.second + direction[i][1];
				if (board[nextI][nextJ] == '#') break;
				else if (make_pair(nextI, nextJ) == posB) {
					releaning = true;
					break;
				}
				newPosR = { nextI, nextJ };
				if (board[nextI][nextJ] == 'O') break;
			}

			while (true) {
				int nextI = newPosB.first + direction[i][0];
				int nextJ = newPosB.second + direction[i][1];
				if (board[nextI][nextJ] == '#') break;
				else if (board[nextI][nextJ] == 'O') {
					newPosB = { nextI, nextJ };
					break;
				}
				else if (make_pair(nextI, nextJ) == newPosR) break;
				newPosB = { nextI, nextJ };
				
			}

			while (releaning) {
				int nextI = newPosR.first + direction[i][0];
				int nextJ = newPosR.second + direction[i][1];
				if (board[nextI][nextJ] == '#') break;
				else if (board[nextI][nextJ] == 'O') {
					newPosR = { nextI, nextJ };
					break;
				}
				else if (make_pair(nextI, nextJ) == newPosB) break;
				newPosR = { nextI, nextJ };
				if (board[nextI][nextJ] == 'O') break;
			}
			
			q.push({ cnt + 1, {newPosR.first * M + newPosR.second, newPosB.first * M + newPosB.second} });
		}
	}
	cout << solved << endl;
}

int main(int argc, char const* argv[])
{
	int posB, posR;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'B') posB = i*M + j;
			else if (board[i][j] == 'R') posR = i*M + j;
			else if (board[i][j] == 'O') posO = { i, j };
		}
	}

	solve(posR, posB);

	return 0;
}
