#include <iostream>
#include <string>

using namespace std;

int main() {
	int N, M, K, i, j, k;
	int** A, ** B;

	cin >> N >> M;
	A = new int* [N];
	for (i = 0; i < N; i++) {
		A[i] = new int[M];
		for (j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}

	cin >> M >> K;
	B = new int* [M];
	for (i = 0; i < M; i++) {
		B[i] = new int[K];
		for (j = 0; j < K; j++) {
			cin >> B[i][j];
		}
	}
	
	for (i = 0; i < N; i++) {
		for (k = 0; k < K; k++) {
			int tmp = 0;
			for (j = 0; j < M; j++) {
				tmp += A[i][j] * B[j][k];
			}
			cout << to_string(tmp) + " ";
		}
		cout << endl;
	}
}