#include <iostream>
#include <cstring>
#include <queue>
#include <list>

using namespace std;
int direction[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
int main(int argc, char const* argv[])
{
	int R, C;
	cin >> R >> C;
	int cheese[100][100];
	int time = 0, last_num = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> cheese[i][j];
		}
	}

	while (true) {
		int visited[100][100];
		queue<pair<int, int>> q;
		list<pair<int, int>> melting;

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				visited[i][j] = 0;
			}
		}

		q.push(make_pair(0, 0));

		while (!q.empty()) {
			int r = q.front().first;
			int c = q.front().second;
			q.pop();
			visited[r][c] = 1;
			
			for (int i = 0; i < 4; i++) {
				int new_r = r + direction[i][0];
				int new_c = c + direction[i][1];
				
				if (new_r >= 0 && new_c >= 0 && new_r < R && new_c < C && visited[new_r][new_c] != 1) {
					if (cheese[new_r][new_c] == 0) {
						q.push(make_pair(new_r, new_c));
						visited[new_r][new_c] = 1;
					}
					else {
						melting.push_front(make_pair(new_r, new_c));
						visited[new_r][new_c] = 1;
					}
				}
			}
		}

		if (melting.size() == 0) break;
		last_num = melting.size();
		time++;
		for (list<pair<int, int>>::iterator iter = melting.begin(); iter != melting.end(); iter++) {
			cheese[(*iter).first][(*iter).second] = 0;
		}
	}

	cout << time << "\n" << last_num << endl;

	
	return 0;
}