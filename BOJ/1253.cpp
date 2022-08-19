#include <iostream>
#include <algorithm>
#include <memory.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
int N, answer = 0;
int num[2000];

bool isGood(int n, int idx) {
	int left = 0, right = N - 1;
	if (left == idx) left++;
	else if (right == idx) right--;
	while (left < right) {
		int sum = num[left] + num[right];
		if (sum > n) right--;
		else if (sum == n) return true;
		else left++;

		if (left == idx) left++;
		else if (right == idx) right--;
	}
	return false;
}

int main(int argc, char const* argv[])
{
	unordered_map<int, int> h;
	cin >> N;
	

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	sort(num, num + N);

	for (int i = 0; i < N; i++) {
		if (isGood(num[i], i)) answer++;
	}

	cout << answer << endl;

	return 0;
}

