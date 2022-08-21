#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N, F;
bool solved;
void solve(int arr[], int left[], int cnt) {
	if (cnt == N) {
		int result[1000];
		for (int i = 0; i < N; i++) result[i] = arr[i];
		for (int i = N - 1; i > 0; i--) {
			for (int j = 0; j < i; j++) {
				result[j] = result[j] + result[j + 1];
			}
		}

		if (result[0] == F) {
			for (int i = 0; i < N; i++) cout << arr[i] << " ";
			solved = true;
		}
		return; 
	}

	for (int i = 1; i <= N; i++) {
		if (left[i] == 0) continue;
		if (solved) break;
		left[i] = 0;
		arr[cnt] = i;
		solve(arr, left, cnt + 1);
		left[i] = 1;
	}
}
int main(int argc, char const* argv[])
{
	
	cin >> N >> F;
	
	int arr[1000];
	int left[1001];
	solved = false;
	for (int i = 1; i <= N; i++) {
		left[i] = 1;
	}
	solve(arr, left, 0);
	
	return 0;
}