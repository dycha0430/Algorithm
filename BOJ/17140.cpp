#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
int arr[100][100];
int cur_r, cur_c;

enum SortType {
    ROW,
    COL
};

void init() {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            arr[i][j] = 0;
        }
    }
    cur_r = 3;
    cur_c = 3;
}

int sort_line(int line_num, SortType sort_type) {
    int count[101];
    for (int i = 1; i <= 100; i++) count[i] = 0;
    if (sort_type == ROW) {
        for (int i = 0; i < cur_c; i++) {
            count[arr[line_num][i]]++;
        }
    } else {
        for (int i = 0; i < cur_r; i++) {
            count[arr[i][line_num]]++;
        }
    }
    
    vector<pair<int, int>> new_arr;
    for (int i = 1; i <= 100; i++) {
        if (count[i] != 0) {
            new_arr.push_back({count[i], i});
        }
    }

    sort(new_arr.begin(), new_arr.end());
    int size = new_arr.size();
    int ret_num = min(100, size * 2);
    for (int i = 0; i < ret_num/2; i++) {
        if (sort_type == ROW) {
            arr[line_num][i*2] = new_arr[i].second;
            arr[line_num][i*2+1] = new_arr[i].first;
        } else {
            arr[i*2][line_num] = new_arr[i].second;
            arr[i*2+1][line_num] = new_arr[i].first;
        }
    }

    for (int i = ret_num; i < 100; i++) {
        if (sort_type == ROW) arr[line_num][i] = 0;
        else arr[i][line_num] = 0;
    }
    return ret_num;
}

void play_turn() {
    int num = cur_c;
    SortType sort_type = COL;
    if (cur_r >= cur_c) {
        num = cur_r;
        sort_type = ROW;
    } 

    int max_num = 0;
    for (int i = 0; i < num; i++) {
        max_num = max(max_num, sort_line(i, sort_type));
    }

    if (sort_type == ROW) cur_c = max_num;
    else cur_r = max_num;
}

int main() {
    int r, c, k;
    cin >> r >> c >> k;

    init();
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    int answer = -1;
    for (int t = 0; t <= 100; t++) {
        if (arr[r-1][c-1] == k) {
            answer = t;
            break;
        }

        play_turn();
    }

    cout << answer << endl;
}