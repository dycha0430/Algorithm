#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

int N, M;
int** office;
vector<pair<int, int>> cctv;
int K;
int dir_1[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
int dir_2[2][2][2] = { {{0, 1}, {0, -1}}, {{1, 0}, {-1, 0}} };
int dir_3[4][2][2] = { {{0, -1}, {1, 0}}, {{1, 0}, {0 ,1}}, {{0, 1}, {-1, 0}}, {{-1, 0}, {0, -1}} };
int dir_4[4][3][2] = { {{0, -1}, {1, 0}, {0, 1}}, {{1, 0}, {0, 1}, {-1, 0}}, {{0, 1}, {-1, 0}, {0, -1}}, {{-1, 0}, {0, -1}, {1, 0}} };
int answer = 10000;

void copy_office(int** origin, int** copy) {
	for (int i = 0; i < N; i++) {
		copy[i] = new int[M];
		for (int j = 0; j < M; j++) {
			copy[i][j] = origin[i][j];
		}
	}
}
void solve(int idx) {
	if (idx == K) {
		int tmp = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (office[i][j] == 0) tmp++;
			}
		}
		answer = min(answer, tmp);
		return;
	}

	int cctv_r = cctv[idx].first, cctv_c = cctv[idx].second;
	int cctv_type = office[cctv_r][cctv_c];

	int** office_copy = new int* [N];
	copy_office(office, office_copy);
	if (cctv_type == 1) {
		for (int i = 0; i < 4; i++) {
			int tmp_r = cctv_r + dir_1[i][0], tmp_c = cctv_c + dir_1[i][1];
			while (tmp_r < N && tmp_r >= 0 && tmp_c < M && tmp_c >= 0 && office_copy[tmp_r][tmp_c] != 6) {
				if (office[tmp_r][tmp_c] == 0)
					office[tmp_r][tmp_c] = 7;
				tmp_r += dir_1[i][0];
				tmp_c += dir_1[i][1];
			}
			solve(idx + 1);
			copy_office(office_copy, office);
		}
	}
	else if (cctv_type == 2) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				int tmp_r = cctv_r - dir_2[i][j][0], tmp_c = cctv_c - dir_2[i][j][1];
				while (tmp_r < N && tmp_r >= 0 && tmp_c < M && tmp_c >= 0 && office_copy[tmp_r][tmp_c] != 6) {
					if (office[tmp_r][tmp_c] == 0)
						office[tmp_r][tmp_c] = 7;
					tmp_r -= dir_2[i][j][0];
					tmp_c -= dir_2[i][j][1];
				}
			}
			solve(idx + 1);
			copy_office(office_copy, office);
		}
	}
	else if (cctv_type == 3) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 2; j++) {
				int tmp_r = cctv_r + dir_3[i][j][0], tmp_c = cctv_c + dir_3[i][j][1];
				while (tmp_r < N && tmp_r >= 0 && tmp_c < M && tmp_c >= 0 && office_copy[tmp_r][tmp_c] != 6) {
					if (office[tmp_r][tmp_c] == 0)
						office[tmp_r][tmp_c] = 7;
					tmp_r += dir_3[i][j][0];
					tmp_c += dir_3[i][j][1];
				}
			}
			solve(idx + 1);
			copy_office(office_copy, office);
		}
	}
	else if (cctv_type == 4) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 3; j++) {
				int tmp_r = cctv_r + dir_4[i][j][0], tmp_c = cctv_c + dir_4[i][j][1];
				while (tmp_r < N && tmp_r >= 0 && tmp_c < M && tmp_c >= 0 && office_copy[tmp_r][tmp_c] != 6) {
					if (office[tmp_r][tmp_c] == 0)
						office[tmp_r][tmp_c] = 7;
					tmp_r += dir_4[i][j][0];
					tmp_c += dir_4[i][j][1];
				}
			}
			solve(idx + 1);
			copy_office(office_copy, office);
		}
	}
	else if (cctv_type == 5) {
		for (int i = 0; i < 4; i++) {
			int tmp_r = cctv_r + dir_1[i][0], tmp_c = cctv_c + dir_1[i][1];
			while (tmp_r < N && tmp_r >= 0 && tmp_c < M && tmp_c >= 0 && office_copy[tmp_r][tmp_c] != 6) {
				if (office[tmp_r][tmp_c] == 0)
					office[tmp_r][tmp_c] = 7;
				tmp_r += dir_1[i][0];
				tmp_c += dir_1[i][1];
			}
		}
		solve(idx + 1);
		copy_office(office_copy, office);
	}
}

int main(int argc, char const* argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	office = new int* [N];
	for (int i = 0; i < N; i++) {
		office[i] = new int[M];
		for (int j = 0; j < M; j++) {
			cin >> office[i][j];
			if (office[i][j] > 0 && office[i][j] < 6) cctv.emplace_back(i, j);
		}
	}

	K = cctv.size();
	solve(0);
	cout << answer;

	return 0;
}

