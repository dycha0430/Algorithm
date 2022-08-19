#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int getArea2(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
	return abs(a.first * b.second + b.first * c.second + c.first * a.second - b.first * a.second - c.first * b.second - a.first * c.second);
}

int main(int argc, char const* argv[])
{
	int N;
	cin >> N;
	
	vector<pair<int, int>> dots;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		dots.push_back(make_pair(a, b));
	}

	int answer = 0;
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				answer = max(answer, getArea2(dots[i], dots[j], dots[k]));
			}
		}
	}

	if (answer % 2) cout << answer / 2 << ".5" << endl;
	else cout << answer / 2 << ".0" << endl;

	return 0;
}
