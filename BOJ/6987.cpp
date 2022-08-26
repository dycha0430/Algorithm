#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int result[4][6][3];
int answer[4];
int first[] = { 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4 };
int second[] = { 1, 2, 3, 4, 5, 2, 3, 4, 5, 3, 4, 5, 4, 5, 5 };
int tmp_result[6][3];

void solve(int cnt) {
	if (cnt == 15) {
		for (int i = 0; i < 4; i++) {
			if (answer[i] == 1) continue;
			bool isTrue = true;
			for (int j = 0; j < 6; j++) {
				for (int k = 0; k < 3; k++) {
					if (result[i][j][k] != tmp_result[j][k]) {
						isTrue = false;
						break;
					}
				}
				if (!isTrue) break;
			}

			if (isTrue) answer[i] = 1;
		}
		return;
	}

	tmp_result[first[cnt]][0]++;
	tmp_result[second[cnt]][2]++;
	solve(cnt + 1);

	tmp_result[first[cnt]][0]--;
	tmp_result[second[cnt]][2]--;
	tmp_result[first[cnt]][1]++;
	tmp_result[second[cnt]][1]++;
	solve(cnt + 1);

	tmp_result[first[cnt]][1]--;
	tmp_result[second[cnt]][1]--;
	tmp_result[first[cnt]][2]++;
	tmp_result[second[cnt]][0]++;
	solve(cnt + 1);

	tmp_result[first[cnt]][2]--;
	tmp_result[second[cnt]][0]--;
}

int main(int argc, char const* argv[])
{
	for (int i = 0; i < 4; i++) {
		answer[i] = 0;
		for (int j = 0; j < 6; j++) {
			for (int k = 0; k < 3; k++) {
				tmp_result[j][k] = 0;
				cin >> result[i][j][k];
			}
		}
	}
	solve(0);
	
	for (int i = 0; i < 4; i++) cout << answer[i] << " ";
	return 0;
}
