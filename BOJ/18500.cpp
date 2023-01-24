#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int R, C;
char map[100][100];
int direction[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
vector<pair<int, int>> cluster;

void down() {
    while (true) {
        bool is_end = false;
        for (vector<pair<int, int>>::iterator iter = cluster.begin(); iter < cluster.end(); iter++)
        {
            int next_i = (*iter).first+1;
            int next_j = (*iter).second;
            if (next_i == R || (map[next_i][next_j] == 'x' && find(cluster.begin(), cluster.end(), make_pair(next_i, next_j)) == cluster.end())) {
                is_end = true;
                break;
            }
        }

        if (is_end) break;

        for (vector<pair<int, int>>::iterator iter = cluster.begin(); iter < cluster.end(); iter++)
        {
            map[(*iter).first][(*iter).second] = '.';
        }

        for (vector<pair<int, int>>::iterator iter = cluster.begin(); iter < cluster.end(); iter++)
        {
            map[(*iter).first + 1][(*iter).second] = 'x';
            iter->first++;
        }
    }
    
}

void rearrange_map(int dest_i, int dest_j) {
    for (int i = 0; i < 4; i++) {
        int next_i = dest_i + direction[i][0];
        int next_j = dest_j + direction[i][1];

        if (next_i < 0 || next_j < 0 || next_i >= R || next_j >= C) {
            continue;
        }

        cluster.clear();
        queue<pair<int, int>> q;
        bool visit[100][100];
        for (int x = 0; x < R; x++) {
            for (int y = 0; y < C; y++)
                visit[x][y] = false;
        }
        q.push({next_i, next_j});
        bool should_down = true;
        while (!q.empty()) {
            int curr_i = q.front().first;
            int curr_j = q.front().second;
            q.pop();

            if (visit[curr_i][curr_j] || map[curr_i][curr_j] == '.') continue;
            visit[curr_i][curr_j] = true;
            cluster.push_back({curr_i, curr_j});
            
            if (curr_i == R-1) {
                should_down = false;
                break;
            }

            for (int d = 0; d < 4; d++) {
                int next_i2 = curr_i + direction[d][0];
                int next_j2 = curr_j + direction[d][1];
                if (next_i2 < 0 || next_j2 < 0 || next_i2 >= R || next_j2 >= C)
                    continue;

                q.push({next_i2, next_j2});
            }
        }
        if (!cluster.empty() && should_down) {
            down();
            break;
        }
    }
    
}

int main(void) {
    int N, height;
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
        }
    }
    cin >> N;
    for (int t = 0; t < N; t++) {
        int dx = 1;
        int loc = 0;
        if (t % 2) {
            dx = -1;
            loc = C-1;
        }
        cin >> height;
        while (loc >= 0 && loc < C) {
            if (map[R-height][loc] == 'x') {
                map[R-height][loc] = '.';
                break;
            }
            loc += dx;
        }

        if (loc >= 0 && loc < C) 
            rearrange_map(R-height, loc);
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << map[i][j];
        }
        cout << endl;
    }
}