#include <iostream>
#include <algorithm>
#include <memory.h>
#include <math.h>

using namespace std;
typedef long long ll;

const int MAX = 1000001;
bool prime[MAX];
int N;

// 골드바흐의 추측 : 2보다 큰 모든 짝수는 두 소수의 합으로 표현 가능
pair<int, int> getTwoPrime(int sum) {
	for (int i = 2; i <= MAX; i++) {
		if (!prime[i]) continue;
		else if (prime[sum - i]) {
			return make_pair(i, sum - i);
		}
	}

	return make_pair(-1, -1);
}

int main(int argc, char const* argv[])
{
	cin >> N;

	if (N < 8) {
		cout << "-1";
		return 0;
	}

	memset(prime, 1, sizeof(bool) * MAX);
	prime[1] = false;
	for (int i = 2; i <= sqrt(MAX); i++) {
		if (!prime[i]) continue;
		int remove = i*2;
		while (remove < MAX) {
			prime[remove] = false;
			remove += i;
		}
	}

	if (N % 2 == 0) {
		pair<int, int> ret = getTwoPrime(N - 4);
		cout << "2 2 " << ret.first << " " << ret.second;
	}
	else {
		pair<int, int> ret = getTwoPrime(N - 5);
		cout << "2 3 " << ret.first << " " << ret.second;
	}
	
	return 0;
}