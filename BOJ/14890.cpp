#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

int N, L;
int** map;

bool canPass(bool isRow, int idx) {
	bool ret = true;
	bool higherPlaceBefore = false;
	int consecutiveNum = 1;
	for (int i = 0; i < N-1; i++) {
		int curr = isRow ? map[idx][i] : map[i][idx];
		int next = isRow ? map[idx][i + 1] : map[i + 1][idx];

		if (curr == next) {
			consecutiveNum++;
			continue;
		}

		if (higherPlaceBefore) {
			higherPlaceBefore = false;
			if (consecutiveNum < L) {
				ret = false;
				break;
			}
			else {
				consecutiveNum -= L;
			}
		}

		if (curr == next + 1) {
			higherPlaceBefore = true;
		}
		else if (curr + 1 == next) {
			if (consecutiveNum < L) {
				ret = false;
				break;
			}
		}
		else {
			ret = false;
			break;
		}
		consecutiveNum = 1;
	}

	if (higherPlaceBefore && consecutiveNum < L) {
		ret = false;
	}

	return ret;
}

int main(int argc, char const* argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L;
	map = new int* [N];
	for (int i = 0; i < N; i++) {
		map[i] = new int[N];
		for (int j = 0; j < N; j++) cin >> map[i][j];
	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		if (canPass(true, i)) answer++;
		if (canPass(false, i)) answer++;
	}
	cout << answer;

	return 0;
}

