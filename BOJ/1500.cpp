#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;
ll cache[101][21];
int K;

ll dp(int sum, int num);

int main(int argc, char const* argv[])
{
	int S;
	cin >> S >> K;

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 21; j++) cache[i][j] = -1;
	}

	cout << dp(S, K);

	return 0;
}

ll dp(int sum, int num) {
	if (num == 1) return sum;
	if (num > sum) return 0;
	ll& ret = cache[sum][num];
	if (ret != -1) return ret;
	
	for (int i = 1; i <= sum-num+1; i++) {
		ret = max(ret, dp(sum - i, num - 1) * i);
	}

	return ret;
}

