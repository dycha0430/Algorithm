#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const* argv[])
{
	int N;
	int T[16], P[16];
	int dp[17];
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
		dp[i] = 0;
	}
	dp[N + 1] = 0;

	for (int i = N; i > 0; i--) {
		if (i + T[i] - 1 > N) {
			dp[i] = dp[i + 1];
			continue;
		}
		dp[i] = max(P[i] + dp[i + T[i]], dp[i + 1]);
	}
	
	cout << dp[1] << endl; 
	return 0;
}