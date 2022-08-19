#include <iostream>

using namespace std;

int gcd(int a, int b) {
	if (a % b == 0) return b;
	return gcd(b, a % b);
}

int main(int argc, char const* argv[])
{
	int N, K;
	cin >> N >> K;
	cout << K - gcd(N, K);
	return 0;
}