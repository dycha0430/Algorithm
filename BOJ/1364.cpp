#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;

int main(int argc, char const* argv[])
{
	int N;
	cin >> N;
	ll mul6 = 0;
	ll i = 0;
	ll bound = 1;
	
	while (N > mul6) {
		mul6 += 6;
		bound += mul6;
		i++;
	}

	ll answer = 0;
	if (N == mul6) answer = bound;
	else if (N == mul6 - 1) answer = bound - 1 - i;
	else answer = bound - 1 - i * (mul6 - N);

	cout << answer;	

	return 0;
}