#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;
typedef long long ll;
int main(int argc, char const* argv[])
{
	ll N, answer = 0;
	double B, C;
	cin >> N;
	double* A = new double[N];
	for (int i = 0; i < N; i++) cin >> A[i];
	cin >> B >> C;

	for (int i = 0; i < N; i++) {
		A[i] -= B;
		answer += 1;
		if (A[i] > 0) {
			answer += ceil(A[i] / C);
		}
	}

	cout << answer;

	return 0;
}
