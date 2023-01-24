#include <iostream>
#include <queue>
#include <functional>
#define MAX 100000

using namespace std;
bool visited[MAX+1];

int solve(int N, int K) {
    // time, location
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, N});
    while (!q.empty()) {
        int time = q.top().first;
        int loc = q.top().second;
        q.pop();
        if (loc == K) return time;
        if (visited[loc]) continue;
        visited[loc] = true;
        if (loc+1 <= MAX)
            q.push({time+1, loc+1});
        if (loc-1 >= 0)
            q.push({time+1, loc-1});
        if (loc*2 <= MAX)
            q.push({time, loc*2});
    }
    return 0;
}

int main() {
    int N, K;
    cin >> N >> K;
    for (int i = 0; i <= MAX; ++i) visited[i] = false;
    cout << solve(N, K) << endl;
}