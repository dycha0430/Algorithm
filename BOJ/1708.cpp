#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

vector<pair<int, int>> coordinates;
int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        coordinates.push_back({x, y});
    }
}