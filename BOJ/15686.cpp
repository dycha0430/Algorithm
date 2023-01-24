#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#define MAX 1000000000

using namespace std;

vector<pair<int, int>> chickens;
vector<pair<int, int>> houses;
int selected[13];
int N, M;

int combination(int select_num, int last_selected_chicken_idx) {
    if (select_num == M) {
        int ret = 0;
        for (vector<pair<int, int>>::iterator house = houses.begin(); house < houses.end(); house++) {
            int min_distance = MAX;
            for (int chicken_idx = 0; chicken_idx < M; chicken_idx++) {
                min_distance = min(min_distance, abs(house->first - chickens[selected[chicken_idx]].first) + abs(house->second - chickens[selected[chicken_idx]].second));
            }
            ret += min_distance;
        }
        return ret;
    }

    int ret = MAX;
    int total = chickens.size();
    for (int i = last_selected_chicken_idx + 1; i <= total - (M - select_num); i++) {
        selected[select_num] = i;
        ret = min(ret, combination(select_num+1, i));
    }

    return ret;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int input;
            cin >> input;
            if (input == 1)
            {
                houses.push_back({i, j});
            }
            else if (input == 2)
            {
                chickens.push_back({i, j});
            }
        }
    }

    cout << combination(0, -1) << endl;    
}