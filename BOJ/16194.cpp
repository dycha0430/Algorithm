#include <iostream>
#include <algorithm>

using namespace std;
int main(int argc, char const* argv[])
{
	int N;
	cin >> N;
	int cost[1001];
	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
	}

	int dp[1001];
	dp[0] = 0;
	for (int i = 1; i <= N; i++) {
		dp[i] = cost[i];
		for (int j = 0; j <= i / 2; j++) {
			dp[i] = min(dp[i], dp[i - j] + dp[j]);
		}
	}
	
	cout << dp[N];
	return 0;
}