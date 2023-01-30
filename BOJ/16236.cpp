#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#define MAX 10000
using namespace std;

int space[20][20];
int N;
int shark_size;
int direction[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

pair<int, int> find_next_fish(pair<int, int> shark) {
    queue<pair<int, int>> q;
    bool visit[20][20];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) visit[i][j] = false;
    }
    q.push({shark.first * N + shark.second, 0});

    int found_cnt = MAX;
    pair<int, int> found_fish = {MAX, MAX};
    while (!q.empty()) {
        int x = q.front().first / N;
        int y = q.front().first % N;
        int cnt = q.front().second;
        
        q.pop();
        if (visit[x][y]) continue;
        if (found_cnt < cnt) break;
        if (space[x][y] != 0 && space[x][y] < shark_size) {
            found_cnt = cnt;
            if (found_fish.first > x) found_fish = {x, y};
            else if (found_fish.first == x && found_fish.second > y) found_fish = {x, y};
        }
        visit[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int next_x = x + direction[i][0];
            int next_y = y + direction[i][1];
            if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= N) continue;
            else if (visit[next_x][next_y]) continue;
            else if (space[next_x][next_y] > shark_size) continue;
            q.push({next_x * N + next_y, cnt+1});
        }
    }
    
    if (found_cnt != MAX) {
        space[found_fish.first][found_fish.second] = 0;
        return {found_fish.first * N + found_fish.second, found_cnt};
    }
    // can't find eatable fish.
    return {-1, -1};
}

int eat_fish(pair<int, int> shark)
{
    int time = 0;
    int eaten_fish = 0;
    while (true) {
        pair<int, int> ret = find_next_fish(shark);
        int x = ret.first / N;
        int y = ret.first % N;
        int cnt = ret.second;
        if (cnt == -1) break;
        shark = {x, y};
        time += cnt;
        eaten_fish++;
        if (eaten_fish == shark_size) {
            eaten_fish = 0;
            shark_size++;
        }
    }

    return time;
}
int main() {
    cin >> N;
    pair<int, int> shark_pos;
    shark_size = 2;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> space[i][j];
            if (space[i][j] == 9) {
                shark_pos = {i, j};
                space[i][j] = 0;
            }
        }
    }
    
    cout << eat_fish(shark_pos);

}