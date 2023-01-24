#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#define MAX 100000000
using namespace std;

int N, M;
vector<int> virus_locs;
int selected_virus_indeces[10];
int direction[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int lab[50][50];

int get_spread_time() {
    int lab_copy[50][50];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) lab_copy[i][j] = lab[i][j];
    }
    queue<pair<int, int>> q;
    for (int i = 0; i < M; i++)
    {
        int loc = virus_locs[selected_virus_indeces[i]];
        q.push({loc, 0});
        lab_copy[loc/N][loc%N] = 3;
    }

    int ret_cnt = 0;
    while (!q.empty()) {
        int x = q.front().first / N;
        int y = q.front().first % N;
        int count = q.front().second;
        
        q.pop();

        bool contains_empty_space = false;
        for (int i = 0; i < 4; i++) {
            int next_x = x + direction[i][0];
            int next_y = y + direction[i][1];

            if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= N || lab_copy[next_x][next_y] == 1 || lab_copy[next_x][next_y] == 3) continue;
            q.push({next_x * N + next_y, count+1});
            if (lab_copy[next_x][next_y] == 0) contains_empty_space = true;
            lab_copy[next_x][next_y] = 3;
        }
        if (contains_empty_space)
            ret_cnt = max(ret_cnt, count+1);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) {
            if (lab_copy[i][j] == 0) return MAX;
        }
    }
    return ret_cnt;
}

int combination(int selected_num, int last_selected_idx) {
    if (selected_num == M) {
        return get_spread_time();
    }
    
    int total = virus_locs.size();
    int answer = MAX;
    for (int i = last_selected_idx+1; i <= total - (M - selected_num); i++) {
        selected_virus_indeces[selected_num] = i;
        answer = min(answer, combination(selected_num+1, i));
    }

    return answer;
}

int main(void) {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> lab[i][j];
            if (lab[i][j] == 2) {
                virus_locs.push_back(i*N+j);
            }
        }
    }

    int answer = combination(0, -1);
    if (answer == MAX) answer = -1;
    cout << answer << endl;

    
}