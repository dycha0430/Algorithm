#include <iostream>
#include <algorithm>

using namespace std;

int N;
int loss[20], happy[20];

int solve(int last_idx, int hp, int happiness) {
	bool end = true;
	int ret = 0;
	for (int i = last_idx; i < N; i++) {
		if (hp - loss[i] <= 0) continue;
		end = false;
		ret = max(ret, solve(i + 1, hp - loss[i], happiness + happy[i]));
	}

	if (end) ret = happiness;

	return ret;
}

int main(int argc, char const* argv[])
{
	cin >> N;
	for (int i = 0; i < N; i++) cin >> loss[i];
	for (int i = 0; i < N; i++) cin >> happy[i];
	
	cout << solve(0, 100, 0);

	return 0;
}