#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <memory.h>

using namespace std;
typedef long long ll;
int N, M;
int seat[40];
int cache[41];

// n 개의 자유로운 좌석에서 앉을 수 있는 경우의 수
int swap_num(int n) {
	if (n == 0) return 1;
	else if (n == 1) return 1;
	else if (n == 2) return 2;
	int& ret = cache[n];
	if (ret != -1) return ret;

	return ret = swap_num(n - 2) + swap_num(n - 1);
}

int main(int argc, char const* argv[])
{
	cin >> N >> M;
	
	memset(seat, 0, sizeof(int) * N);
	memset(cache, -1, sizeof(int) * 41);
	for (int i = 0; i < M; i++) {
		int tmp;
		cin >> tmp;
		seat[tmp - 1] = 1;
	}

	int answer = 1;
	int sequence_num = 0;
	for (int i = 0; i < N; i++) {
		if (seat[i] == 1) {
			answer *= swap_num(sequence_num);
			sequence_num = 0;
		}
		else sequence_num++;
	}

	answer *= swap_num(sequence_num);

	cout << answer << endl;

	return 0;
}