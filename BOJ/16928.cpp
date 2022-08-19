#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

class Info {
	public:
		int pos;
		int square_num;
		int depth;
		void setInfo(int _pos, int square_num, int depth);
};

void Info::setInfo(int _pos, int _square_num, int _depth) {
	pos = _pos;
	square_num = _square_num;
	depth = _depth;
}

int game[101];
bool visited[101];
int main(int argc, char const* argv[])
{
	int N, M;
	cin >> N >> M;
	
	memset(visited, false, sizeof(bool) * 101);
	memset(game, 0, sizeof(int) * 101);

	int x, y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		game[x] = y;
	}

	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		game[x] = y;
	}

	queue<Info> q;
	for (int i = 1; i <= 6; i++) {
		Info tmp;
		tmp.setInfo(1, i, 1);
		q.push(tmp);
	}

	while (!q.empty()) {
		Info info = q.front();
		int pos = info.pos;
		int square_num = info.square_num;
		int depth = info.depth;
		q.pop();
		
		int next_pos = pos + square_num;
		if (game[next_pos] != 0) next_pos = game[next_pos];
		if (visited[next_pos]) continue;
		visited[next_pos] = true;

		if (next_pos > 100) continue;
		else if (next_pos == 100) {
			cout << depth << endl;
			return 0;
		}

		for (int i = 1; i <= 6; i++) {
			Info new_info;
			new_info.setInfo(next_pos, i, depth + 1);
			q.push(new_info);
		}
	}
	return 0;
}