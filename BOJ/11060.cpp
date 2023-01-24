#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

int MAX = 10000;

int main(int argc, char const* argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	int* maze = new int[N];
	int* reach_to_end = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> maze[i];
		reach_to_end[i] = MAX;
	}
	reach_to_end[N - 1] = 0;

	for (int i = N - 2; i >= 0; i--) {
		if (i + maze[i] >= N - 1) {
			reach_to_end[i] = 1;
		}
		else {
			for (int j = maze[i]; j >= 1; j--) {
				reach_to_end[i] = min(reach_to_end[i], reach_to_end[i + j] + 1);
			}
		}
	}

	if (reach_to_end[0] == MAX) cout << "-1";
	else cout << reach_to_end[0];

	return 0;
}

