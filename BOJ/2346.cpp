#include <iostream>
#include <deque>

using namespace std;

int inf = -1001;
int main(int argc, char const* argv[])
{
	int N, tmp;
	cin >> N;
	deque<pair<int, int>> arr;
	
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		arr.push_back(make_pair(i+1, tmp));
	}
	
	int loc = 0;
	for (int i = 0; i < N; i++) {
		cout << arr.front().first << " ";
		int step = arr.front().second;
		arr.pop_front();
		if (step < 0) {
			for (int i = 0; i > step; i--) {
				arr.push_front(make_pair(arr.back().first, arr.back().second));
				arr.pop_back();
			}
		}
		else if (step > 0) {
			for (int i = 0; i < step - 1; i++) {
				arr.push_back(make_pair(arr.front().first, arr.front().second));
				arr.pop_front();
			}
		}
	}
	return 0;
}