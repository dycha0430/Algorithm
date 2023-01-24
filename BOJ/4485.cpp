#include <iostream>
#include <queue>
#include <functional>
#include <climits>

using namespace std;

int map[125][125];
int cache[125][125];
int MAX = INT_MAX;
int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int solve(int N) {
    // cost, idx
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({map[0][0], 0});
    cache[0][0] = map[0][0];

    while (!pq.empty()) {
        int cost = pq.top().first;
        int idx = pq.top().second;
        int y = idx / N;
        int x = idx % N;
        pq.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = y + direction[i][0];
            int nx = x + direction[i][1];
            int ncost = map[ny][nx];
            
            if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                continue;
            if (cache[ny][nx] > cost + ncost) {
                cache[ny][nx] = cost + ncost;
                pq.push({cache[ny][nx], ny * N + nx});
            }
        }
    }

    return cache[N-1][N-1];
}

int main(void) {
    int problem = 0;
    while (true) {
        int N;
        cin >> N;
        if (N == 0) break;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> map[i][j];
                cache[i][j] = MAX;
            }
        }

        cout << "Problem " << ++problem << ": " << solve(N) << endl;
    }
}