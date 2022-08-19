#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;
typedef long long ll;
bool visited[2100][2100];

class Imoji {
	public:
		int time;
		int num;
		int clipboard;

		Imoji(int a, int b, int c) {
			time = a;
			num = b;
			clipboard = c;
		}
};

int main(int argc, char const* argv[])
{
	int S;
	cin >> S;
	
	queue<Imoji> q;
	q.push(Imoji(1, 1, 1));
	int min_time = 100000;
	for (int i = 0; i < 2100; i++) {
		for (int j = 0; j < 2100; j++) visited[i][j] = false;
	}

	while (!q.empty()) {
		int time = q.front().time;
		int num = q.front().num;
		int clipboard = q.front().clipboard;
		q.pop();
		if (visited[num][clipboard]) continue;
		visited[num][clipboard] = true;

		if (num > 1) q.push(Imoji(time + 1, num - 1, clipboard));
		if (num + clipboard == S) {
			cout << min(time+1, min_time) << endl;
			break;
		} else if (num + clipboard > S) {
			min_time = min(min_time, time + 1 + num + clipboard - S);
			continue;
		}
		q.push(Imoji(time + 1, num + clipboard, clipboard));
		if (num == clipboard) continue;
		q.push(Imoji(time + 1, num, num));
	}
	return 0;
}
