#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
ll cache[31];

ll count(int width) {
	if (width == 0) return 1;
	else if (width == 1) return 1;
	ll& ret = cache[width];
	if (ret != -1) return ret;
	
	return ret = count(width - 2) * 2 + count(width - 1);
}

int main(int argc, char const* argv[])
{
	int N;
	cin >> N;
	for (int i = 0; i <= 30; i++) cache[i] = -1;

	ll answer = count(N);
	answer += count(N / 2);
	if (N % 2 == 0) {
		answer += count(N / 2 - 1) * 2;
	}
	cout << answer / 2 << endl;
	
	return 0;
}