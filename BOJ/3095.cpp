#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int main(int argc, char const* argv[])
{
	int N;
	int answer = 0;
	int** acc_sum, **arr;
	cin >> N;
	acc_sum = new int*[N+1];
	arr = new int*[N+1];
	for (int i = 0; i <= N; i++) {
		arr[i] = new int[N+1];
		acc_sum[i] = new int[N+1];
		memset(acc_sum[i], 0, sizeof(int) * (N + 1));
		memset(arr[i], 0, sizeof(int) * (N + 1));
	}

	char c;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> c;
			arr[i][j] = c - '0';
			acc_sum[i][j] = acc_sum[i][j - 1] + acc_sum[i - 1][j] - acc_sum[i - 1][j - 1] + arr[i][j];
		}
	}

	for (int i = 2; i < N; i++) {
		for (int j = 2; j < N; j++) {
			if (!arr[i][j] || !arr[i - 1][j] || !arr[i][j - 1] || !arr[i + 1][j] || !arr[i][j + 1]) continue;
			
			int k = 0;
			while (true) {
				int iend = i + 1 + k;
				int jend = j + 1 + k;
				int istart = i - 1 - k;
				int jstart = j - 1 - k;
				if (iend > N || jend > N || istart <= 0 || jstart <= 0) break;
				if (!arr[iend][j] || !arr[i][jend] || !arr[istart][j] || !arr[i][jstart]) break;
				if (acc_sum[iend][jend] - acc_sum[iend][jstart - 1] - acc_sum[istart - 1][jend] + acc_sum[istart - 1][jstart - 1] != (3 + 2*k) * 2 - 1) break;
				answer++;
				k++;
			}
		}
	}

	cout << answer;
	
	return 0;
}