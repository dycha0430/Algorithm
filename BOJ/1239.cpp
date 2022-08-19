#include <iostream>
#include <algorithm>

using namespace std;

int N;
int dogs[8];

void swap(int& i, int& j) {
	int tmp = i;
	i = j;
	j = tmp;
}
int permutation(int* arr, int depth) {
	if (depth == N) {
		int answer = 0;
		for (int i = 0; i < N; i++) {
			int sum = 0;
			int j = i;
			while (sum < 50) {
				sum += arr[j];
				j = (j+1) % N;
			}
			if (sum == 50) answer++;
		}
		return answer / 2;
	}
	
	int ret = 0;
	for (int i = depth; i < N; i++) {
		swap(arr[depth], arr[i]);
		ret = max(ret, permutation(arr, depth + 1));
		swap(arr[depth], arr[i]);
	}

	return ret;
}
int main(int argc, char const* argv[])
{
	cin >> N;
	for (int i = 0; i < N; i++) cin >> dogs[i];

	cout << permutation(dogs, 0);
	return 0;
}